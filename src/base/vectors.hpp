#ifndef _VECTORS_HPP
#define _VECTORS_HPP

#include <stdio.h>
#include "new_types/new_types_definitions.hpp"

namespace nissa
{
  char *get_vect_name(void *v);
  int check_borders_allocated(void *data);
  int check_borders_communicated_at_least_once(void *data);
  int check_borders_valid(void *data);
  int check_edges_allocated(void *data);
  int check_edges_valid(void *data);
  int64_t compute_vect_memory_usage();
  int get_vect_flag(void *v,unsigned int flag);
  nissa_vect* get_vect(void *v);
  void *internal_nissa_malloc(const char *tag,int64_t nel,int64_t size_per_el,const char *type,const char *file,int line);
  void crash_if_borders_not_allocated(void *v);
  void crash_if_edges_not_allocated(void *v);
  void ignore_borders_communications_warning(void *data);
  void initialize_main_vect();
  void internal_nissa_free(char **arr,const char *file,int line);
  void vector_copy(void *a,void *b);
  void vector_reset(void *a);
  void last_vect_content_printf();
  void vect_content_fprintf(FILE *fout,nissa_vect *vect);
  void vect_content_printf(nissa_vect *vect);
  void print_all_vect_content();
  void reorder_vector(char *vect,int *order,int nel,int sel);
  void set_borders_invalid(void *data);
  void set_borders_valid(void *data);
  void set_edges_invalid(void *data);
  void set_edges_valid(void *data);
  void set_vect_flag(void *v,unsigned int flag);
  void set_vect_flag_non_blocking(void *v,unsigned int flag);
  void unset_vect_flag(void *v,unsigned int flag);
  void unset_vect_flag_non_blocking(void *v,unsigned int flag);
  void vect_content_fprintf(FILE *f,void *vec);
  void vect_content_printf(void *vec);
}
#endif
  