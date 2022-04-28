//twosum 
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
#include <math.h>
struct hash_table_entry {      //声明结构体
	int hash;          //hash值 =(abs(key % htable_size) + 1) 遇到hash冲突时
	int key;          //关键值
	int value;       //下标值
};

#define hash_fn(key) (abs(key % htable_size) + 1)
#define prob_fn(key) (abs(key % htable_size) + 1)

void  insert_htable(struct hash_table_entry *htable, int htable_size, int key, int value)      //输入hash表函数 *htable为结构体变量
{
	int hash = hash_fn(key); 
	int tmphash = hash;
	while (htable[tmphash].hash)       //遇到hash冲突时继续hash
		tmphash = prob_fn(tmphash);
	htable[tmphash] = (struct hash_table_entry){hash,key,value};
}

int find_htable(struct hash_table_entry *htable, int htable_size, int key, int*found_idx)     //查找hash表函数
{
	int hash = hash_fn(key);
	int tmphash = hash;
	while (htable[tmphash].hash && htable[tmphash].key != key)    //遇到hash冲突时
		tmphash = prob_fn(tmphash);
    *found_idx = htable[tmphash].value;            //找到目标值后传给*found_idx
	return htable[tmphash].hash == hash;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)    //查找值的函数   
{
	int htable_size = numsSize * 2;
	int *p = malloc(sizeof(int) * 2);
	int found_idx;
	struct hash_table_entry *htable = calloc(htable_size + 1, sizeof(struct hash_table_entry));
    *returnSize = 2;
	for (int i = 0; i < numsSize; ++i) {    //遍历整个numsSize
		if (find_htable(htable, htable_size, target - nums[i], &found_idx)) {
			p[0] = found_idx;
			p[1] = i;
			break;
		} else {
			insert_htable(htable, htable_size, nums[i], i);
		}
	}
    free(htable);
    return p;
}
