#ifndef _CONF_HPP
#define _CONF_HPP

namespace nissa
{
  void generate_random_coord(coords);
    void setup_conf(quad_su3 *conf,momentum_t old_theta,momentum_t put_theta,const char *conf_path,int rnd_gauge_transform,int free_theory);
  void random_shift_gauge_conf(quad_su3 *conf,momentum_t old_theta,momentum_t put_theta);
}

#endif