/**********************************************************************
Prescribe a sinusoidal inlet velocity BC
S. Huq, 23 May 2016
Karlsruher Institut fuer Technologie
***********************************************************************/

#include "udf.h"
#define PI 3.14159265


/*
// fu=.1;au=1.;uref=1.;uo=0.;fw=1.;aw=.5;wref=1;wo=-1.; // U @ 0.1; W @ 1.0 Hz
// fu=.1;au=1.;uref=1.;uo=0.;fw=.1;aw=.5;wref=1;wo=-1.; // U @ 0.1; W @ 0.1 Hz
// fu=1.;au=1.;uref=1.;uo=0.;fw=1.;aw=.5;wref=1;wo=-1.; // U @ 1.0; W @ 1.0 Hz
*/

DEFINE_PROFILE(Ux, thread, position)
{
   face_t f;
   real t = CURRENT_TIME;
   
   float fu, au, uref, uo;
   fu=.1;au=1.;uref=1.;uo=0.;

   begin_f_loop(f, thread)
   {    
      F_PROFILE(f, thread, position) = ( 1 + au * sin(2*PI*fu*t) ) * uref + uo;
   }
   end_f_loop(f, thread)
} 

DEFINE_PROFILE(Uz, thread, position)
{
   face_t f;
   real t = CURRENT_TIME;

   float fw, aw, wref, wo;
   fw=1.;aw=.5;wref=1;wo=-1.;
   
   begin_f_loop(f, thread)
   {
     F_PROFILE(f, thread, position) = ( 1 + aw * sin(2*PI*fw*t) ) * wref + wo;
   }
   end_f_loop(f, thread)
} 
