#include <nissa.hpp>

using namespace nissa;

template <typename...Tp>
struct Field
{
  
};

using SpinSpaceColor=TensComps<SpinIdx<ROW>,SpaceIdx,ColorIdx<ROW>>;

template <typename Fund>
using SpinColorField=Tens<SpinSpaceColor,Fund>;

using SpinColorFieldD=SpinColorField<double>;

#define TEST(NAME,...)							\
  double& NAME(SpinColorFieldD& tensor,SpinIdx<ROW> spin,ColorIdx<ROW> col,SpaceIdx space) \
  {									\
    asm("#here " #NAME "  access");					\
    return __VA_ARGS__;							\
  }

SpaceIdx vol;

TEST(seq_fun,bindComp(tensor,col,spin,space).eval())

TEST(bra_fun,tensor[col][spin][space])

TEST(csv_fun,tensor(col,spin,space));

TEST(svc_fun,tensor(spin,space,col));

TEST(hyp_fun,tensor(col)(spin)(space));

TEST(triv_fun,tensor.trivialAccess(col+3*(space+vol*spin)));

template <typename T>
void test_if_ref(T&& t)
{
  const bool b=is_const_lvalue_reference_v<T>;
  std::cout<<"ECCO "<<b<<std::endl;
}

template <typename TOut,
	  typename TIn1,
	  typename TIn2>
void unsafe_su3_prod(TOut&& out,const TIn1& in1,const TIn2& in2)
{
  SpaceIdx s(0);
  
  for(ColorIdx<ROW> i1{0};i1<3;i1++)
    for(ColorIdx<COL> k2{0};k2<3;k2++)
      {
  	out(i1,k2,s)=0.0;
  	for(ColorIdx<COL> i2(0);i2<3;i2++)
  	  out(i1,k2,s)+=in1(i1,i2,s)*in2(i2.transp(),k2,s);
      }
}

int main()
{
  using std::cout;
  using std::cin;
  using std::endl;
  
  cout<<"Please enter volume: ";
  cin>>vol;
  
  /// Spinspacecolor
  Tens<SpinSpaceColor,double> tensor(vol);
  
  /// Fill the spincolor with flattened index
  for(SpinIdx<ROW> s(0);s<4;s++)
    for(SpaceIdx v(0);v<vol;v++)
      for(ColorIdx<ROW> c(0);c<3;c++)
  	tensor(s,v,c)=c+3*(v+vol*s);
  
  // Read components to access
  cout<<"Please enter spin, space and color index to printout: ";
  
  /// Spin component
  SpinIdx<ROW> spin;
  cin>>spin;
  
  /// Space component
  SpaceIdx space;
  cin>>space;
  
  /// Color component
  ColorIdx<ROW> col;
  cin>>col;
  
  double& hyp=hyp_fun(tensor,spin,col,space);
  
  /// Spin,space,color access
  double& svc=svc_fun(tensor,spin,col,space);
  
  /// Color,spin,space access
  double& csv=csv_fun(tensor,spin,col,space);
  
  /// Color,spin,space access
  double& seq=seq_fun(tensor,spin,col,space);
  
  /// Color,spin,space access with []
  double& bra=bra_fun(tensor,spin,col,space);
  
  /// Trivial spin access
  double& t=triv_fun(tensor,spin,col,space);
  
  using SU3FieldComps=TensComps<ColorIdx<ROW>,ColorIdx<COL>,SpaceIdx>;
  
  using SU3Field=Tens<SU3FieldComps,double>;
  
  SU3Field conf1(vol),conf2(vol),conf3(vol);
  
  using ComplComps=TensComps<ComplIdx>;
  // Binder<const Tens<std::tuple<TensorCompIdx<_Color, ROW, 0>,
  // 			       TensorCompIdx<_Color, COL, 0>,
  // 			       TensorCompIdx<_Space, ANY, 0> >,
  // 		    double>&,
  // 	 const Tens<std::tuple<TensorCompIdx<_Color, ROW, 0>,
  // 			       TensorCompIdx<_Color, COL, 0>,
  // 			       TensorCompIdx<_Space, ANY, 0> >,
  // 		    double>&,
  // 	 TensorCompIdx<_Color, COL, 0>,
  // 	 TensorCompIdx<_Color, ROW, 0>,
  // 	 TensorCompIdx<_Space, ANY, 0> >
  //const double a=0.0;
  //remove_const_if_ref(a)=0.0;
    Tens<ComplComps,double> test;
  test.trivialAccess(0)=0.0;
  
    for(SpaceIdx v(0);v<vol;v++)
      for(ColorIdx<ROW> c1(0);c1<3;c1++)
	for(ColorIdx<COL> c2(0);c2<3;c2++)
	  conf1(space,c1,c2)=conf2(space,c1,c2)=conf3(space,c1,c2)=0.0;
  
  unsafe_su3_prod(conf1,conf2,conf3);
  
  conf1(ColorIdx<COL>{0},ColorIdx<ROW>{1},SpaceIdx{0})=1.0;
  cout<<"Transp: "<<transpose(conf1(SpaceIdx{0})(ColorIdx<ROW>{1}))(ColorIdx<ROW>{0})<<endl;
  
  cout<<"Test:";
  cout<<" "<<conf1[space][col][col.transp()];
  cout<<" "<<svc;
  cout<<" "<<csv;
  cout<<" "<<t;
  cout<<" "<<seq;
  cout<<" "<<hyp;
  cout<<" "<<bra;
  cout<<" expected: "<<col+3*(space+vol*spin)<<endl;
  
  cout<<SpinColorFieldD::stackAllocated<<endl;
  cout<<SU3Field::stackAllocated<<endl;
  
  return 0;
}