#ifndef _ALL_TO_ALL_COMM_HPP
#define _ALL_TO_ALL_COMM_HPP

namespace nissa
{
  //all to all communicators initializing structure
  struct all_to_all_gathering_list_t : std::map<int,int>
  {int add_conf_link_for_paths(coords g,int mu);};
  struct all_to_all_scattering_list_t : std::vector<std::pair<int,int> > {};
  struct temp_build_t
  {
    int *nper_rank_to_temp,*nper_rank_fr_temp;
    int *out_buf_cur_per_rank,*in_buf_cur_per_rank;
    std::map<int,int> rank_to_map_list_ranks_to,rank_fr_map_list_ranks_fr;
    temp_build_t();
    ~temp_build_t();
  };
  
  //all to all communicators
  struct all_to_all_comm_t
  {
    int nel_out,nel_in;
    int nranks_fr,*list_ranks_fr,*in_buf_dest,*nper_rank_fr,*in_buf_off_per_rank;
    int nranks_to,*list_ranks_to,*out_buf_source,*nper_rank_to,*out_buf_off_per_rank;
    
    all_to_all_comm_t(all_to_all_gathering_list_t &gl);
    all_to_all_comm_t(all_to_all_scattering_list_t &sl);
    ~all_to_all_comm_t();
    void communicate(void *out,void *in,size_t bps,void *buf_out=NULL,void *buf_in=NULL,int tag=-1);
    
    void setup_knowing_where_to_send(all_to_all_scattering_list_t &sl);
    void setup_knowing_what_to_ask(all_to_all_gathering_list_t &gl);
    void setup_nper_rank_other_temp(int *nper_rank_other_temp,int *nper_rank_temp);
    void common_setup_part1(temp_build_t &build);
    void common_setup_part2(int nel_note,int *&buf_note,int nranks_note,int *list_ranks_note,int *buf_note_off_per_rank,int *nper_rank_note,int *buf_expl,int nranks_expl,int *list_ranks_expl,int *buf_expl_off_per_rank,int *nper_rank_expl);
    all_to_all_comm_t() {};
  };
  
  struct vector_remap_t : all_to_all_comm_t
  {
    vector_remap_t(int nel_out,void (*index)(int &irank_to,int &iel_to,int iel_fr,void *pars),void *pars);
    void remap(void *out,void *in,size_t bps){communicate(out,in,bps);}
  };
}

#endif