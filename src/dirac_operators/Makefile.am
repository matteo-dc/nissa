######################################## dirac operators#####################################

__top_builddir__lib_libnissa_a_SOURCES+= \
	%D%/momenta/MFACC.cpp \
	%D%/stD/dirac_operator_stD.cpp \
	%D%/tmD_eoprec/dirac_operator_tmD_eoprec.cpp \
	%D%/tmQ/dirac_operator_tmQ.cpp \
	%D%/tmQ_left/dirac_operator_tmQ_left.cpp \
	%D%/tmQ2/dirac_operator_tmQ2.cpp \
	%D%/tmQ/reconstruct_tm_doublet.cpp \
	%D%/tmclovD_eoprec/dirac_operator_tmclovD_eoprec.cpp \
	%D%/tmclovQ/reconstruct_tmclov_doublet.cpp \
	%D%/Wstat/dirac_operator_Wstat.cpp \
	%D%/WclovQ/dirac_operator_WclovQ.cpp \
	%D%/WclovQ2/dirac_operator_WclovQ2.cpp \
	%D%/tmclovQ/dirac_operator_tmclovQ.cpp \
	%D%/overlap/dirac_operator_overlap_kernel_portable.cpp \
	%D%/overlap/dirac_operator_overlap_kernel2.cpp \
	%D%/overlap/dirac_operator_overlap.cpp \
	%D%/tmclovQ/dirac_operator_tmclovQ_128.cpp \
	%D%/tmclovQ2/dirac_operator_tmclovQ2.cpp \
	%D%/tmclovQ2/dirac_operator_tmclovQ2_128.cpp \
	%D%/tmQ/dirac_operator_tmQ_128.cpp \
	%D%/tmD_eoprec/dirac_operator_tmD_eoprec_128.cpp \
	%D%/tmclovD_eoprec/dirac_operator_tmclovD_eoprec_128.cpp \
	%D%/tmQ2/dirac_operator_tmQ2_128.cpp

include_HEADERS+= \
	%D%/momenta/MFACC.hpp \
	%D%/stD/dirac_operator_stD.hpp\
	%D%/tmD_eoprec/dirac_operator_tmD_eoprec.hpp \
	%D%/tmD_eoprec/dirac_operator_tmD_eoprec_128.hpp \
	%D%/tmQ/dirac_operator_tmQ.hpp \
	%D%/tmQ/reconstruct_tm_doublet.hpp \
	%D%/tmQ/dirac_operator_tmQ_128.hpp \
	%D%/tmQ_left/dirac_operator_tmQ_left.hpp \
	%D%/tmQ2/dirac_operator_tmQ2.hpp \
	%D%/tmQ2/dirac_operator_tmQ2_128.hpp \
	%D%/tmclovD_eoprec/dirac_operator_tmclovD_eoprec.hpp \
	%D%/tmclovQ/dirac_operator_tmclovQ.hpp \
	%D%/tmclovQ/dirac_operator_tmclovQ_128.hpp \
	%D%/tmclovQ/reconstruct_tmclov_doublet.hpp \
	%D%/Wstat/dirac_operator_Wstat.hpp \
	%D%/WclovQ/dirac_operator_WclovQ.hpp \
	%D%/WclovQ2/dirac_operator_WclovQ2.hpp \
	%D%/tmclovQ2/dirac_operator_tmclovQ2.hpp \
	%D%/tmclovD_eoprec/dirac_operator_tmclovD_eoprec_128.hpp \
	%D%/tmclovQ2/dirac_operator_tmclovQ2_128.hpp \
	%D%/overlap/dirac_operator_overlap_kernel2.hpp \
	%D%/overlap/dirac_operator_overlap_kernel_portable.hpp \
	%D%/overlap/dirac_operator_overlap.hpp

#compile or not bgq source
if BGQ
__top_builddir__lib_libnissa_a_SOURCES+= \
	%D%/tmD_eoprec/dirac_operator_tmD_eoprec_bgq.cpp \
	%D%/tmQ/dirac_operator_tmQ_bgq.cpp \
	%D%/tmQ2/dirac_operator_tmQ2_bgq.cpp \
	%D%/tmQ2/dirac_operator_tmQ2_128_bgq.cpp \
	%D%/tmclovD_eoprec/dirac_operator_tmclovD_eoprec_bgq.cpp \
	%D%/tmclovQ/dirac_operator_tmclovQ_bgq.cpp \
	%D%/tmclovQ2/dirac_operator_tmclovQ2_bgq.cpp \
	%D%/tmclovQ2/dirac_operator_tmclovQ2_128_bgq.cpp \
	%D%/stD/dirac_operator_stD_bgq.cpp
include_HEADERS+= \
	%D%/tmD_eoprec/dirac_operator_tmD_eoprec_bgq.hpp \
	%D%/tmQ/dirac_operator_tmQ_bgq.hpp \
	%D%/tmQ2/dirac_operator_tmQ2_bgq.hpp \
	%D%/tmQ2/dirac_operator_tmQ2_128_bgq.hpp \
	%D%/tmclovD_eoprec/dirac_operator_tmclovD_eoprec_bgq.hpp \
	%D%/tmclovQ/dirac_operator_tmclovQ_bgq.hpp \
	%D%/tmclovQ2/dirac_operator_tmclovQ2_bgq.hpp \
	%D%/tmclovQ2/dirac_operator_tmclovQ2_128_bgq.hpp \
	%D%/stD/dirac_operator_stD_bgq.hpp
endif

EXTRA_DIST= \
	base/git_info.hpp \
	%D%/WclovQ/dirac_operator_WclovQ_portable.cpp \
	%D%/stD/dirac_operator_stD_portable.cpp \
	%D%/stD/dirac_operator_stD_32_portable.cpp \
	%D%/stD/dirac_operator_stD_bgq_template.cpp \
	%D%/tmclovD_eoprec/dirac_operator_tmclovD_eoprec_portable.cpp \
	%D%/tmD_eoprec/dirac_operator_tmD_eoprec_portable.cpp \
	%D%/tmQ/dirac_operator_tmQ_portable.cpp \
	%D%/tmQ_left/dirac_operator_tmQ_left_portable.cpp
