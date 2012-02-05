#include "dog_math.h"
#include "constants.h"
#include "tensors.h"

void ApplyLimiter(const dTensor2& node, const dTensorBC3& aux, dTensorBC3& q, 
		  void (*ProjectRightEig)(const dTensor1&,const dTensor1&,const dTensor2&,dTensor2&),
		  void (*ProjectLeftEig)(const dTensor1&,const dTensor1&,const dTensor2&,dTensor2&))
{
  // -------------------------------------------------------------  
  // Limiter based on the following paper:
  //      L. Krivodonova. "Limiters for high-order discontinuous
  //      Galerkin methods." J. Comp. Phys., Vol. 226, pg 879-896.
  // -------------------------------------------------------------
  
  int i,m;
  int melems = q.getsize(1);
  int   meqn = q.getsize(2);
  int   kmax = q.getsize(3);
  int    mbc = q.getmbc();
  int   maux = aux.getsize(2);
  dTensorBC3   w_cent(melems,meqn,kmax-1,mbc);
  dTensorBC3 dw_right(melems,meqn,kmax-1,mbc);
  dTensorBC3  dw_left(melems,meqn,kmax-1,mbc);
  void ConvertQtoW(const dTensorBC3&,const dTensorBC3&,dTensorBC3&,dTensorBC3&,dTensorBC3&,
		   void (*ProjectLeftEig)(const dTensor1&,const dTensor1&,const dTensor2&,dTensor2&));
  void ConvertWtoQ(const dTensorBC3&,const dTensorBC3&,const dTensorBC3&,dTensorBC3&,
		   void (*ProjectRightEig)(const dTensor1&,const dTensor1&,const dTensor2&,dTensor2&));
  double dw1_right, dw1_left, w2_now, w2_limited;
  double dw2_right, dw2_left, w3_now, w3_limited;
  double dw3_right, dw3_left, w4_now, w4_limited;
  double dw4_right, dw4_left, w5_now, w5_limited;
  double dx = node.get(2,1)-node.get(1,1);
  
  // Convert to characteristic variables
  ConvertQtoW(aux,q,dw_right,dw_left,w_cent,ProjectLeftEig);
  
  // Moment limiter (highest to lowest)
  switch ( kmax )
    {
      // ****************************************************************
      case 2:  // 2nd order in space	 
      
	//#pragma omp parallel for
	for (i=(3-mbc); i<=(melems+mbc-2); i++)
	  for (m=1; m<=meqn; m++)
	    {
	      // limit highest moment
	      dw1_right  = dw_right.get(i,m,1);
	      dw1_left   = dw_left.get(i,m,1);
	      w2_now     = w_cent.get(i,m,1);
	      w2_limited = minmod(w2_now, dw1_right/sq3, dw1_left/sq3);
		
	      w_cent.set(i,m,1, w2_limited );	   
	    }

	break;
	
      // ****************************************************************
      case 3:  // 3rd order in space	 

	//#pragma omp parallel for	
	for (i=(3-mbc); i<=(melems+mbc-2); i++)	  
	  for (m=1; m<=meqn; m++)
	    {
	      // limit highest moment
	      dw2_right  = dw_right.get(i,m,2);
	      dw2_left   = dw_left.get(i,m,2);
	      w3_now     = w_cent.get(i,m,2);
	      w3_limited =minmod(w3_now, (sq3/sq5)*dw2_right, (sq3/sq5)*dw2_left);
	      
	      w_cent.set(i,m,2, w3_limited );
	      
	      // only limit next order if highest moment was limited
	      if (fabs(w3_now - w3_limited)>1.0e-14 || 
		  fabs(w3_limited)<1.0e-14)
		{
		  dw1_right  = dw_right.get(i,m,1);
		  dw1_left   = dw_left.get(i,m,1);
		  w2_now     = w_cent.get(i,m,1);
		  w2_limited = minmod(w2_now, dw1_right/sq3, dw1_left/sq3);
		  
		  w_cent.set(i,m,1, w2_limited );
		}		  
	    }
	break;
	  
      // ****************************************************************
      case 4:  // 4th order in space	 
	
	//#pragma omp parallel for
	for (i=(3-mbc); i<=(melems+mbc-2); i++)	 
	  for (m=1; m<=meqn; m++)
	    {
	      dw3_right  = dw_right.get(i,m,3);
	      dw3_left   = dw_left.get(i,m,3);
	      w4_now     = w_cent.get(i,m,3);
	      w4_limited =minmod(w4_now, (sq5/sq7)*dw3_right, 
				 (sq5/sq7)*dw3_left);
	      
	      w_cent.set(i,m,3, w4_limited );
	      
	      // only limit next order if previous moment was limited
	      if (fabs(w4_now - w4_limited)>1.0e-14 || 
		  fabs(w4_limited)<1.0e-14)
		{		      
		  dw2_right  = dw_right.get(i,m,2);
		  dw2_left   = dw_left.get(i,m,2);
		  w3_now     = w_cent.get(i,m,2);
		  w3_limited =minmod(w3_now, (sq3/sq5)*dw2_right, 
				     (sq3/sq5)*dw2_left);
		  
		  w_cent.set(i,m,2, w3_limited );
		  
		  // only limit next order if previous moment was limited
		  if (fabs(w3_now - w3_limited)>1.0e-14 || 
		      fabs(w3_limited)<1.0e-14)
		    {
		      dw1_right  = dw_right.get(i,m,1);
		      dw1_left   = dw_left.get(i,m,1);
		      w2_now     = w_cent.get(i,m,1);
		      w2_limited = minmod(w2_now, dw1_right/sq3, 
					  dw1_left/sq3);
		      
		      w_cent.set(i,m,1, w2_limited );
		    }		
		}  
	    }	  
	break;
	  
      // ****************************************************************
      case 5:  // 5th order in space	 
	  
	//#pragma omp parallel for
	for (i=(3-mbc); i<=(melems+mbc-2); i++)	  
	  for (m=1; m<=meqn; m++)
	    {
	      dw4_right  = dw_right.get(i,m,4);
	      dw4_left   = dw_left.get(i,m,4);
	      w5_now     = w_cent.get(i,m,4);
	      w5_limited =minmod(w5_now, (sq7/3.0)*dw4_right, 
				 (sq7/3.0)*dw4_left);
	      
	      w_cent.set(i,m,4, w5_limited );
	      
	      // only limit next order if previous moment was limited
	      if (fabs(w5_now - w5_limited)>1.0e-14 || 
		  fabs(w5_limited)<1.0e-14)
		{
		  dw3_right  = dw_right.get(i,m,3);
		  dw3_left   = dw_left.get(i,m,3);
		  w4_now     = w_cent.get(i,m,3);
		  w4_limited =minmod(w4_now, (sq5/sq7)*dw3_right, 
				     (sq5/sq7)*dw3_left);
		  
		  w_cent.set(i,m,3, w4_limited );
		  
		  // only limit next order if previous moment was limited
		  if (fabs(w4_now - w4_limited)>1.0e-14 || 
		      fabs(w4_limited)<1.0e-14)
		    {
		      
		      dw2_right  = dw_right.get(i,m,2);
		      dw2_left   = dw_left.get(i,m,2);
		      w3_now     = w_cent.get(i,m,2);
		      w3_limited =minmod(w3_now, (sq3/sq5)*dw2_right, 
					 (sq3/sq5)*dw2_left);
		      
		      w_cent.set(i,m,2, w3_limited );
		      
		      // only limit next order if previous moment was limited
		      if (fabs(w3_now - w3_limited)>1.0e-14 || 
			  fabs(w3_limited)<1.0e-14)
			{
			  dw1_right  = dw_right.get(i,m,1);
			  dw1_left   = dw_left.get(i,m,1);
			  w2_now     = w_cent.get(i,m,1);
			  w2_limited = minmod(w2_now, dw1_right/sq3, 
					      dw1_left/sq3);
			  
			  w_cent.set(i,m,1, w2_limited );
			}		
		    }  
		}
	    }	  
	break;
    }

  // Convert characteristic variables to conserved variables
  ConvertWtoQ(aux,q,w_cent,q,ProjectRightEig);
 
}
