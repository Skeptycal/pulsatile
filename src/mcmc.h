///-----------------------------------------------------------------------------
///
/// FILE: mcmc.h
///
/// DESCRIPTION: 
///   Function definitions for linklistv3.c
/// 
///-----------------------------------------------------------------------------

#ifndef MCMC_H
#define MCMC_H

// Include this here since defn of structures used in arguments

#endif 

#include "r_interface.h"
#include "pulse_node.h"

void mcmc(Node_type *list, Common_parms *parms, double **ts, long iter, int N,
          int nthin, int burnin, int strauss, int verbose, Priors *priors, 
          SEXP common, SEXP pulse_chains, double propsd[]);

void mh_time_strauss(Node_type *list, Common_parms *parms, double **ts, 
                     double *like, int N, double sd, Priors *priors, 
                     long *atime, long *ntime);

void mh_time_os(Node_type *list, Common_parms *parms, double **ts, 
                double *like, int N, double v, long *atime, long *ntime,
                int mmm);

void mh_mu_delta(Node_type *list, Common_parms *parms, Priors *priors, 
                 double **ts, double *like, int N, int num_node, double **var,
                 long *adelta, long *ndelta);

void draw_fixed_effects(Node_type *list, Priors *priors, Common_parms *parms,
                        double sdfem, double sdfew, long *afem_ptr, 
                        long *nfem_ptr, long *afew_ptr, long *nfew_ptr); 


void draw_re_sd(Node_type *list, Priors *priors, Common_parms *parms, 
                double v1, double v2, long *arevm, long *nrevm, 
                long *arevw, long *nrevw);

void draw_random_effects(double **ts, Node_type *list, Common_parms *parms, 
                         int N, double *like, double v1,  double v2, 
                         long *arem, long *nrem, long *arew, 
                         long *nrew);

void draw_eta(Node_type *list, Common_parms *parms, double sdm, double sdw,
              long *aetam, long *aetaw, long *netam, long *netaw);

double error_squared(double **ts, Node_type *list, Common_parms *parms, int N);

void adjust_acceptance(double x, double *X);

void adjust2_acceptance(double x, double **X, double corr);

//------------------------------------------------------------------------------
// End of file
//------------------------------------------------------------------------------

