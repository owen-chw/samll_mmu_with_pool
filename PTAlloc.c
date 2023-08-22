#include "test.h"

/*
 * PTAlloc
 */

// initialize pool for vm
void initialize_memory_pool(u32 vmid){
  nextPtr[vmid] = (u64*) malloc(PAGE_PER_VM * PAGE_SIZE * sizeof(u64));
  if (nextPtr[vmid] != NULL){
    endPtr[vmid] = nextPtr[vmid] + PAGE_PER_VM * PAGE_SIZE * sizeof(u64);
    printf("initialize success\nnextPtr is %llu\nendPtr is %llu\n", nextPtr[vmid], endPtr[vmid]);
  } else {
    printf("initialize fail\n");
  }
}


u64 alloc_s2pt_pgd(u32 vmid)
{
	u64 next, end;

	next = nextPtr[vmid];
	end = endPtr[vmid];

	if (next + (PAGE_SIZE * sizeof(u64)) <= end)
	{
    nextPtr[vmid] += (PAGE_SIZE * sizeof(u64));
    return check64(next);
  }
	else
	{
    printf("all memory space for PT of vm%i has been used\n", vmid);
    return 0;
	}
}

u64 alloc_s2pt_pud(u32 vmid)
{
	u64 next, end;

	next = nextPtr[vmid];
	end = endPtr[vmid];

	if (next + (PAGE_SIZE * sizeof(u64)) <= end)
	{
    nextPtr[vmid] += (PAGE_SIZE * sizeof(u64));
    return check64(next);
  }
	else
	{
    printf("all memory space for PT of vm%i has been used\n", vmid);
    return 0;
	}
}

u64 alloc_s2pt_pmd(u32 vmid)
{
	u64 next, end;

	next = nextPtr[vmid];
	end = endPtr[vmid];

	if (next + (PAGE_SIZE * sizeof(u64)) <= end)
	{
    nextPtr[vmid] += (PAGE_SIZE * sizeof(u64));
    return check64(next);
  }
	else
	{
    printf("all memory space for PT of vm%i has been used\n", vmid);
    return 0;
	}
}

int main(void){
  initialize_memory_pool(1);
  printf("new PGD addr is %llu \n", alloc_s2pt_pgd(1));
  printf("new PUD addr is %llu \n", alloc_s2pt_pud(1));
  printf("new PMD addr is %llu \n", alloc_s2pt_pmd(1));
  printf("new PMD addr is %llu \n", alloc_s2pt_pmd(1));
  return 0;

}