// ==============================================================================
// This file is part of THOR.
//
//     THOR is free software : you can redistribute it and / or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     THOR is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//     GNU General Public License for more details.
//
//     You find a copy of the GNU General Public License in the main
//     THOR directory under <license.txt>.If not, see
//     <http://www.gnu.org/licenses/>.
// ==============================================================================
//
//
//
// Description: Defines debug parameters and enable helper functions
//
// Method: -
//
// Known limitations: None
//
//
// Known issues: None
//
//
// If you use this code please cite the following reference:
//
//       [1] Mendonca, J.M., Grimm, S.L., Grosheintz, L., & Heng, K., ApJ, 829, 115, 2016
//
// Current Code Owners: Joao Mendonca (joao.mendonca@space.dtu.dk)
//                      Russell Deitrick (russell.deitrick@csh.unibe.ch)
//                      Urs Schroffenegger (urs.schroffenegger@csh.unibe.ch)
//
// History:
// Version Date       Comment
// ======= ====       =======
// 2.0     30/11/2018 Released version (RD & US)
// 1.0     16/08/2017 Released version  (JM)
//
////////////////////////////////////////////////////////////////////////

// benchmarking
// if defined run benchmark functions?
// #define BENCHMARKING

// ***************************************
// * binary comparison
// compare benchmark point to references
// use --bincompare option
// write reference benchmark point
// use --binwrite option
// print out more debug info, by default, only print out failures
// #define BENCH_PRINT_DEBUG
// print out comparisaon statistics
// #define BENCH_COMPARE_PRINT_STATISTICS
// use an epsilon value for fuzzy compare on relative value
// #define BENCH_COMPARE_USE_EPSILON
// #define BENCH_COMPARE_EPSILON_VALUE 1e-14
// ***************************************
// * check for NaNs
// #define BENCH_NAN_CHECK
// * below adds checks on device functions (useful for device memory bugs)
// #define BENCH_CHECK_LAST_CUDA_ERROR

// path to benchmark result directory
#define BENCHMARK_DUMP_REF_PATH "results/ref/"
#define BENCHMARK_DUMP_BASENAME "bindata_"

//*****************************************************************************
//#define STEP_TIMING_INFO

//*****************************************************************************
// diagnostics tests
// test that matrix used in vertical implicit solver in thor_vertical_int.h is
// diagonaly dominant

// magnitude factor mag for comparison in diagonal dominance
// a_ii > mag * sum(a_ij, i!=j)
#define THOMAS_DIAG_DOM_FACTOR 1.0


// diagnostics levels
// general enabler of checks
#define DIAGNOSTICS_LEVEL1
//#define DIAGNOSTICS_LEVEL2
//#define DIAGNOSTICS_LEVEL3
// #define DIAGNOSTICS_LEVEL4

#ifdef DIAGNOSTICS_LEVEL4
#    define DIAGNOSTICS_LEVEL3
#    define DIAG_CHECK_THOR_VERTICAL_INT_THOMAS_RESULT
#endif // DIAGNOSTICS_LEVEL3

#ifdef DIAGNOSTICS_LEVEL3
#    define DIAGNOSTICS_LEVEL2
#    define DIAG_CHECK_THOR_VERTICAL_INT_THOMAS_DIAG_DOM
#endif // DIAGNOSTICS_LEVEL3


#ifdef DIAGNOSTICS_LEVEL2
#    define DIAGNOSTICS_LEVEL1
#    define DIAG_CHECK_DENSITY_PRESSURE_EQ_AUX
#endif // DIAGNOSTICS_LEVEL2

#ifdef DIAGNOSTICS_LEVEL1
#    define DIAG_CHECK_DENSITY_PRESSURE_EQ_P_NAN
#    define DIAG_CHECK_BL_THOMAS_DIAG_DOM
#endif // DIAGNOSTICS_LEVEL1
