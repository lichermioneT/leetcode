# LeetCode

## 611

给定一个包含非负整数的数组 `nums` ，返回其中可以组成三角形三条边的三元组个数。

**示例 1:**

```
输入: nums = [2,2,3,4]
输出: 3
解释:有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
```

**示例 2:**

```
输入: nums = [4,2,3,4]
输出: 4
```

**总结**

 0  1  2  3  4  5  6

 [2, 2, 3, 4, 5, 9, 10]

 2+9已经大于10了，左边单调递增的，所以这区间的全部符合。right--

2+5已经小于10了，右边单调递减的，所以需要区间变大。letf++

然后重复

**c++版本**

```c++
class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        // 任意 a + b > c;
        // 这里可以计算重复的
        // a<=b<=c -- 这里只需要判断 a+b>c。c无论加上a,b都是大的。
        // 优化先对数据进行排序
        /*
            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                    for(k = 0; k < n; k++)
                        check(i, j k)     3 * n3  nlogn + n3
            0   1  2  3  4  5   6
            [2, 2, 3, 4, 5, 9, 10]
             2+9 > 10 已经大于10现在只需要 right--; right-left种方法
             2+5 < 10 已经小于10现在只需要 left++;
             letf==right时 10--。
        
        1.固定最大的数
        2.最大数左边区间，双指针计算
        3.
        */

        sort(nums.begin(), nums.end());
        
        int ret = 0; 
        int n = nums.size();
        for(int i = n - 1; i >= 2; i--)
        {
            // 双指针统计
            int left = 0;
            int right = i - 1;
            while(left < right)
            {
                if(nums[right] + nums[left] > nums[i])
                {
                    ret += right - left;
                    right--;
                }
                else 
                {
                    left++;
                }
            }
        }
        return ret;
    }
};
```



**c语言版本**

```c
int triangleNumber(int* nums, int numsSize) 
{

    for(int i = 0; i < numsSize - 1; i++)
    {
        
        for(int j = 0; j < numsSize - 1 - i; j++)
        {
            if(nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }


    int ret = 0;
    for(int i = numsSize - 1; i >=2; i--)
    {
        int left = 0;
        int right = i-1;
        
        while(left < right)
        {
            if(nums[left] + nums[right] > nums[i])
            {
                ret += right-left;
                right--;
            }
            else 
            {
                left++;
            }
        }
    }

    return ret;
}
```



## 1089

**给你一个长度固定的整数数组 `arr` ，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。**

**注意：请不要在超过该数组长度的位置写入元素。请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。**

**示例 1：**

```
输入：arr = [1,0,2,3,0,4,5,0]
输出：[1,0,0,2,3,0,0,4]
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
```

**示例 2：**

```
输入：arr = [1,2,3]
输出：[1,2,3]
解释：调用函数后，输入的数组将被修改为：[1,2,3]

```

**总结：先找到最后一个复写的元素。**

**可能复写的最后元素可能是零，所以需要单独处理一下**

**不是零的直接进行处理就行。**



**c++实现版本**

```c++
class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int sz = arr.size();
        int cur = 0;
        int i = 0;
        while(cur < sz)
        {
            if(arr[i]  == 0)
            {
                cur += 2;
            }
            else 
            {
                cur += 1;
            }
            i++;
        }

        i--;
        int index = sz-1;
        
        if(cur > sz)
        {
            arr[index--] = 0;
            i--;
        }

        while(i > 0)
        {
            if(arr[i] == 0)
            {
                arr[index--] = 0;
                arr[index--] = 0;
            }
            else 
            {
                arr[index--] = arr[i];
            }
            i--;
        }

        // int n = arr.size();
        // int cur = 0;  // 判断满了没得
        // int i = 0;   // 需要复写的最后一个元素。

        // // 1. 找到最后一个会被处理的元素
        // while (cur < n) 
        // {
        //     if (arr[i] == 0) cur += 2;
        //     else cur += 1;
        //     i++;
        // }

        // i--;                // 最后一个有效原数组元素
        // int index = n - 1;  // 实际写入位置

        // // 2. 处理“多出来的 0”
        // if (cur > n) 
        // {      // 说明最后是 0，只能写一个
        //     arr[index] = 0;
        //     index--;
        //     i--;
        // }

        // // 3. 从后往前写
        // while (i >= 0) 
        // {
        //     if (arr[i] == 0) 
        //     {
        //         arr[index--] = 0;
        //         arr[index--] = 0;
        //     } 
        //     else 
        //     {
        //         arr[index--] = arr[i];
        //     }
        //     i--;
        // }

    }
};

```



## 202

编写一个算法来判断一个数 `n` 是不是快乐数。

**「快乐数」** 定义为：

- 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
- 然后重复这个过程直到这个数变为 1，也可能是 **无限循环** 但始终变不到 1。
- 如果这个过程 **结果为** 1，那么这个数就是快乐数。

如果 `n` 是 *快乐数* 就返回 `true` ；不是，则返回 `false` 。

**示例 1：**

```
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

**示例 2：**

```
输入：n = 2
输出：false
```



**c++实现版本**

```c++
class Solution {
public:
//     bool isHappy(int n) 
//     {   
        
//         int slow = n;
//         int fast = bitSum(n);
//         while(slow != fast)
//         {
//             slow = bitSum(slow);
//             fast = bitSum(bitSum(fast));
//         }

//         return fast == 1;
//     }


// private:
//     int bitSum(int n)
//     {
//         int sum = 0;
//         while(n > 0)
//         {
//             int t = n % 10; // 取0-9;
//             sum += t * t;
//             n /= 10;        // 删除一位 
//         }
//         return sum;
//     }

bool isHappy(int n)
{
    int slow = n;
    int fast = bitSum(n);
    while(slow != fast)
    {
        slow = bitSum(slow);
        fast = bitSum(bitSum(fast));
    }
    return fast == 1;
}

private:
    int bitSum(int n)
    {
        int sum = 0;
        while(n)
        {
            int t = n % 10;
            sum += t * t;
            n /= 10;
        }
        return sum;
    }
};
```



## 26

给你一个 **非严格递增排列** 的数组 `nums` ，请你**[ 原地](http://baike.baidu.com/item/原地算法)** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。元素的 **相对顺序** 应该保持 **一致** 。然后返回 `nums` 中唯一元素的个数。

考虑 `nums` 的唯一元素的数量为 `k`。去重后，返回唯一元素的数量 `k`。

`nums` 的前 `k` 个元素应包含 **排序后** 的唯一数字。下标 `k - 1` 之后的剩余元素可以忽略。

**判题标准:**

系统会用下面的代码来测试你的题解:

```
int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

如果所有断言都通过，那么您的题解将被 **通过**。

**示例 1：**

```
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
```

**示例 2：**

```
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4,_,_,_,_,_]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。

```



**c++实现版本**

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // if(nums.empty())
        //     return 0;

        // int index = 0;                 // 记录数组中不重复的元素
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if(nums[index] != nums[i])
        //     {
        //         nums[++index] = nums[i];
        //     }
        // }    

        // return index+1;


        if(nums.empty())
            return 0;

        int index = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[index] != nums[i])
            {
                nums[++index] = nums[i];
            }
        }

        return index+1;
    }
};
```



## 66

给定一个表示 **大整数** 的整数数组 `digits`，其中 `digits[i]` 是整数的第 `i` 位数字。这些数字按从左到右，从最高位到最低位排列。这个大整数不包含任何前导 `0`。

将大整数加 1，并返回结果的数字数组。

**示例 1：**

```
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
加 1 后得到 123 + 1 = 124。
因此，结果应该是 [1,2,4]。
```

**示例 2：**

```
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
加 1 后得到 4321 + 1 = 4322。
因此，结果应该是 [4,3,2,2]。
```

**示例 3：**

```
输入：digits = [9]
输出：[1,0]
解释：输入数组表示数字 9。
加 1 得到了 9 + 1 = 10。
因此，结果应该是 [1,0]。
```





```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // 从最后一位开始加1
        for (int i = n - 1; i >= 0; i--) 
        {
            digits[i]++;  // 当前位加1
            
            if (digits[i] < 10) 
            {
                return digits;  // 没有进位，直接返回
            }
            
            digits[i] = 0;  // 当前位变成0，进位到前一位
        }
        
        // 如果循环结束还没返回，说明最高位也进位了
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```





## LCR179

购物车内的商品价格按照升序记录于数组 `price`。请在购物车中找到两个商品的价格总和刚好是 `target`。若存在多种情况，返回任一结果即可。

**这是一个升序的数组**

**所以你可以优化 排序的**

**示例 1：**

```
输入：price = [3, 9, 12, 15], target = 18
输出：[3,15] 或者 [15,3]
```

**示例 2：**

```
输入：price = [8, 21, 27, 34, 52, 66], target = 61
输出：[27,34] 或者 [34,27]

```



```
[3, 9, 12, 15]
SIZE = 4;
0 1 2 3
SZIE-1 = 3;

<SIZE
<SIZE-1;
```



C++版本

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) 
    {
        int sz = price.size();
        int left = 0;
        int right = sz - 1;
        vector<int> v;
        while(left != right)
        {
            if(price[left] + price[right] > target)
            {
                right--;  // 右边到左边递减
            }
            else if(price[left] + price[right] < target)
            {
                left++; //  左边到右边递增
            }
            else 
            {
                v.push_back(price[left]);
                v.push_back(price[right]);
                break;
            }
        }
        return v;
    }
};
```

**暴力算法**

````c++
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) 
    {
        vector<int> v;
        int sz = price.size();  
        for(int i  = 0; i < sz - 1; i++)
        {
            for(int j = i + 1; j < sz; j++)
            {
                if(price[i] + price[j] == target)
                {
                    v.push_back(price[i]);
                    v.push_back(price[j]);
                    break;
                }
            }
        }
        return v;
    }
};
````



## 15三数之和

给你一个整数数组 `nums` ，判断是否存在三元组 `[nums[i], nums[j], nums[k]]` 满足 `i != j`、`i != k` 且 `j != k` ，同时还满足 `nums[i] + nums[j] + nums[k] == 0` 。请你返回所有和为 `0` 且不重复的三元组。

**注意：**答案中不可以包含重复的三元组。

**示例 1：**

```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
```

**示例 2：**

```
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
```

**示例 3：**

```
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
```



**在 C++ 中，迭代器范围永远遵循 **“左闭右开”** 原则 `[begin, end)`。**

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        //1.暴力解法，暴力枚举。
        //2. 如何去重？

        // 1.先排序，枚举，set去重

        // 1.排序，双指针或者二分法，
        // 找到一种结果之后，跳过重复的元素。 left right 和i
        // 需要两个地方去重 
        // vector<vector<int>> ret;
        // int n = nums.size();
        
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < n; )
        // {
        //     if(nums[i] > 0) break;
        //     int left = i + 1;
        //     int right = n - 1;
        //     int target = -nums[i];

        //     while(left < right)
        //     {
        //         int sum = nums[left] + nums[right];
        //         if(sum > target)
        //         { 
        //             right--;
        //         }
        //         else if(sum < target) 
        //         {
        //             left++;
        //         }
        //         else 
        //         {
        //             ret.push_back({nums[i], nums[left], nums[right]});
        //             left++;
        //             right--;

        //             while(left < right && nums[left] == nums[left-1]) 
        //             {
        //                 left++;
        //             }
        //             while(left < right && nums[right] == nums[right+1]) 
        //             {
        //                 right--;
        //             }
        //         }
        //     }

        //     i++;
        //     while(i < n && nums[i] == nums[i-1]) i++;
        // }
        // return ret;

        vector<vector<int>> ret;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++)
        {
            if(nums[i] > 0) break;

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i + 1;
            int right = n - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum ==  0)
                {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if(sum <  0) 
                {
                    left++;
                }
                else 
                {
                    right--;
                }
            }
        }
        return ret;
    }
};
```



c**语言版本**

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    // for(int i = 0; i < numsSize - 1; i++)
    // {
    //     for(int j = 0; i < numsSize - 1 - i; j++)
    //     {
    //         if(nums[j] > nums[j + 1])
    //         {
    //             int temp = nums[j];
    //             nums[j] = nums[j +1];
    //             nums[j + 1] = temp;
    //         }
    //     }
    // }

    *returnSize = 0;
    if(numsSize < 3)
    {
        return NULL;
    }


    int cmp(const void* a, const void* b)
    {
        return *(int*)a - *(int*)b;
    }
    qsort(nums, numsSize, sizeof(int),  cmp);

    int capacity = numsSize*numsSize;
    int** result = (int**)malloc(sizeof(int*) * capacity);         // 定义一个 capacity*capacity的数组，里面存放指针。
    *returnColumnSizes = (int*)malloc(sizeof(int*) * capacity);    // 


    for(int i = 0; i < numsSize - 2; i++)
    {
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int letf = i + 1;
        int right = numsSize - 1;
        while(letf < right)
        {
            int sum = nums[i] + nums[letf] + nums[right]; // 注意溢出
            if(sum == 0)
            {
                result[*returnSize] = (int*)malloc(sizeof(int)*3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[letf];
                result[*returnSize][2] = nums[right];

                // 记录这一行的列数 (固定是3)
                (*returnColumnSizes)[*returnSize] = 3;
                
                // 结果总数 +1
                (*returnSize)++;

                while(letf < right && nums[letf]  ==  nums[letf   + 1]) letf++;
                while(letf < right && nums[right] ==  nums[right] - 1) right--;
                letf++;
                right--;
            }
            else if(sum < 0) 
            {
                letf++;
            }
            else 
            {
                right--;
            }


        }

    }

    return result;
}
```








## 18四数之和

[18. 四数之和](https://leetcode.cn/problems/4sum/)



给你一个由 `n` 个整数组成的数组 `nums` ，和一个目标值 `target` 。请你找出并返回满足下述全部条件且**不重复**的四元组 `[nums[a], nums[b], nums[c], nums[d]]` （若两个四元组元素一一对应，则认为两个四元组重复）：

- `0 <= a, b, c, d < n`
- `a`、`b`、`c` 和 `d` **互不相同**
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

你可以按 **任意顺序** 返回答案 。

**示例 1：**

```
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**示例 2：**

```
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
```

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        //1. a.固定一个数a, target;
        //2. a []三数之和等于 target-a;
        //3. a b[] 双指针等于 target - a - b;

        // 不重复，不漏
        // a b [left ...  right]

        int n = nums.size();
        if (n < 4) return ret;

        for(int i = 0; i < n - 3; i++) // 固定数a
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < n - 2; j++) // 固定数b;
            {
                if(j >i + 1 && nums[j] == nums[j - 1])  continue;

                int left = j + 1;
                int right = n - 1;

                while(left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target)
                    {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if(sum > target)
                    {
                        right--;
                    }
                    else 
                    {
                        left++;
                    }
                }
            }
        }
        return ret;
    }
};
```





## 209长度最小的子数组

给定一个含有 `n` 个正整数的数组和一个正整数 `target` **。**

找出该数组中满足其总和大于等于 `target` 的长度最小的 **子数组** `[numsl, numsl+1, ..., numsr-1, numsr]` ，并返回其长度**。**如果不存在符合条件的子数组，返回 `0` 。

 

**示例 1：**

```
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```

**示例 2：**

```
输入：target = 4, nums = [1,4,4]
输出：1
```

**示例 3：**

```
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
```



**c++版本**

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        
        // 最短的子数组，并且是连续的数组。
        // 滑动窗口
        // 1.暴力算法
           // [2,3,1,2,4,3]
           // target = 7
           // 暴力枚举全部的数

           //[2 3 1 4]
           // l     r >= target;
           //   l   r
        // 利用单调性，同向双指针,滑动窗口。
        // 怎么用呢？

        // 1.left = 0; right = 0;
        // 2.进入窗口
        // 3.判断 
        //   出窗口
        /*
            r
            2 3 1 2 4 3
            l

            1.l = 0; r  = 0; sum = 0;
            2.进入窗口 sum = 2
            3.进 sum = 5;
            4.进 sum = 6;
            5.进 sum = 8;
                出，更新sum(这里是这道题更新结果。)
                len = r-l
                sum = 6;
                l++(3)
            6.进  sum = 10;
                len = r - l;
                sum = 7;
                l++;(1)
                
                二次判断
                len = r - l;
                sum = 6;
                l++;l=(2)

            7.进
        */

        /*
            为什么是对的？
            单调性：
                  r
            2 3 1 2  4 3
            l

            l+r>=target，已经没有必要枚举后面的了的。
            
        */

        // 时间复杂度2N；N
        int n = nums.size();
        int sum = 0;
        int ret = INT_MAX;
        for(int left = 0, right = 0; right < n; right++)
        {
            sum += nums[right]; // 进入窗口
            while(sum >= target) // 判断
            {
                ret = min(ret, right-left+1); // 跟新结果
                sum -= nums[left++];   // 滚出窗口
            }
        }
        return ret  == INT_MAX ? 0 : ret;
    }

/*
#include <vector>
#include <algorithm>
#include <climits> // 用于 INT_MAX

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = INT_MAX; // 初始化为最大整数，方便后面取最小值

        // 移动 right 指针扩大窗口
        while (right < n) {
            sum += nums[right];

            // 当窗口内的和满足条件时，尝试缩小窗口
            while (sum >= target) {
                // 更新最小长度
                int currentLen = right - left + 1;
                minLen = min(minLen, currentLen);

                // 缩小窗口：减去左边的值，左指针右移
                sum -= nums[left];
                left++;
            }
            
            // 继续扩大窗口
            right++;
        }

        // 如果 minLen 还是 INT_MAX，说明没找到满足条件的子数组，返回 0
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
*/


};
```



























