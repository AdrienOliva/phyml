/*

PHYML :  a program that  computes maximum likelihood  phylogenies from
DNA or AA homologous sequences

Copyright (C) Stephane Guindon. Oct 2003 onward

All parts of  the source except where indicated  are distributed under
the GNU public licence.  See http://www.opensource.org for details.

*/

#include <config.h>

#ifndef AVX_H
#define AVX_H

#include "utilities.h"
#include "optimiz.h"
#include "models.h"
#include "free.h"
#include "times.h"
#include "mixt.h"


#if defined(__AVX__)

void AVX_Update_Partial_Lk(t_tree *tree,t_edge *b_fcus,t_node *n);
__m256d AVX_Horizontal_Add(__m256d x[4]);
void AVX_Update_Eigen_Lr(t_edge *b, t_tree *tree);
phydbl AVX_Lk_Core_One_Class_Eigen_Lr(phydbl *dot_prod, phydbl *expl, unsigned int ns);
phydbl AVX_Lk_Core_One_Class_No_Eigen_Lr(phydbl *p_lk_left,phydbl *p_lk_rght,phydbl *Pij,phydbl *pi,int ns, int ambiguity_check, int observed_state);  
phydbl AVX_Vect_Norm(__m256d _z);
phydbl AVX_Lk_Core(int state, int ambiguity_check, t_edge *b, t_tree *tree);
phydbl AVX_Lk_Core_Nucl(int state, int ambiguity_check, t_edge *b, t_tree *tree);
phydbl AVX_Lk_Core_AA(int state, int ambiguity_check, t_edge *b, t_tree *tree);

#endif
#endif
