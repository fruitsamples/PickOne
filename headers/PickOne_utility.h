/*  PickOne_utility.h																				Nick Thompson	Michael Bishop - August 21 1996														(c)1994-96 Apple Computer Inc., All Rights Reserved								*/#ifndef _UTILITY_H_#define _UTILITY_H_#include	"QD3D.h"#include	"QD3DPick.h"short 		Utility_HiWrd(long aLong) ;short 		Utility_LoWrd(long aLong) ;void		Utility_DebugString(char	*theMessage);void		Utility_MyGetMouse(TQ3Point2D *thePoint);int			Utility_MyStillDown(void);void		Utility_GetUpVector(const TQ3Vector3D *theForwardVector, TQ3Vector3D *theUpVector);TQ3Object	Utility_GetEnclosingGroup(const TQ3HitPath	*theHitPath);#endif