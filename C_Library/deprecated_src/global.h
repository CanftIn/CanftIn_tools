#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*
typedef unsigned int UINT;

typedef struct SINGLENODE_st
{
	struct SINGLENODE_st* pNext;
	void* pData;
}SINGLENODE, *PSINGLENODE;

typedef struct DOUBLENODE_st
{
	struct DOUBLENODE_st* pNext;
	struct DOUBLENODE_st* pPrev;
	void* pData;
}DOUBLENODE;

typedef struct DOUBLELIST_ST
{
	DOUBLENODE* pHead;
	DOUBLENODE* pTail;
	DOUBLENODE* pCur;
	UINT		uCount;
}DOUBLELIST;

*/


/** Generic type data release function
	@param void* pData - release data	
	@return	 - none
*/
typedef void(*DESTROYFUNC)(void* pData);



/**	Generic type data comparison function
@param	void *pData1 
@param	void *pData2 
@return	INT 
*/
typedef INT(*COMPAREFUNC)(void* pData1, void* pData2);



/* Generic traverse execution function
	@param	void *pData 
	@return	void
 */
typedef void(*TRAVERSEFUNC)(void *pData);

/**	Generic iterate execution function
@param	void *pData
@return	void
*/
typedef INT(*VISITFUNC)(void *pData);

/**	Generic data copy function
@param	void *pData 
@return	void * 
*/
typedef void *(*COPYFUNC)(void *pData);


#endif