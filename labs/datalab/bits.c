/*
 * CS:APP Data Lab（位操作实验）
 *
 * Author: jj-balabla
 *
 * bits.c：填写本实验答案的源文件，也是需要提交的文件。
 *
 * 注意：不要引入 <stdio.h>，否则 dlc 可能无法正确解析。
 * 调试时仍可使用 printf，但不引入头文件会使 gcc 发出警告。
 */

#if 0
/*
 * 学生须知：
 *
 * 第 1 步：仔细阅读以下说明。
 */

完成本文件中的函数，即完成 Data Lab。

整数题编码规则：
 
  用一行或多行 C 代码替换每个函数中的占位 return 语句。
  代码应采用以下风格：
 
  int Funct(arg1, arg2, ...) {
      /* 简要说明实现思路 */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  每个 Expr 表达式只能使用：
  1. 0 到 255（0xFF）之间的整数常量；不能直接使用 0xffffffff 等大常量。
  2. 函数参数和局部变量；不能使用全局变量。
  3. 一元整数运算符 ! ~。
  4. 二元整数运算符 & ^ | + << >>。
    
  有些题目进一步限制允许使用的运算符。
  一个表达式可以包含多个运算符，不要求每行只能使用一个运算符。

  明确禁止：
  1. 使用 if、do、while、for、switch 等控制结构。
  2. 定义或使用宏。
  3. 在本文件中定义其他函数。
  4. 调用任何函数。
  5. 使用其他运算符，例如 &&、||、- 或 ?:。
  6. 使用任何形式的类型转换。
  7. 使用 int 以外的类型，因此也不能使用数组、结构体或联合体。

 
  可以假定运行环境：
  1. 使用 32 位二进制补码表示整数。
  2. 对有符号整数执行算术右移。
  3. 当移位量小于 0 或大于 31 时，行为不可预测。


符合规则的代码风格示例：
  /*
   * pow2plus1：当 0 <= x <= 31 时返回 2^x + 1
   */
  int pow2plus1(int x) {
     /* 用移位计算 2 的幂 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4：当 0 <= x <= 31 时返回 2^x + 4
   */
  int pow2plus4(int x) {
     /* 用移位计算 2 的幂 */
     int result = (1 << x);
     result += 4;
     return result;
  }

浮点题编码规则：

浮点题的限制较宽。可以使用循环和条件分支，也可以使用 int 和 unsigned。
整数常量大小不限，可对 int 或 unsigned 数据使用任意算术、逻辑或比较运算。

但明确禁止：
  1. 定义或使用宏。
  2. 在本文件中定义其他函数。
  3. 调用任何函数。
  4. 使用任何形式的类型转换。
  5. 使用 int 和 unsigned 以外的类型，因此也不能使用数组、结构体或联合体。
  6. 使用浮点类型、浮点运算或浮点常量。


补充说明：
  1. 用 dlc 检查答案是否符合规则。
  2. 每个函数都有运算符使用次数上限，由 dlc 检查。
     赋值运算符 = 不计入次数。
  3. 用 btest 检查函数结果是否正确。
  4. 原说明还建议用 BDD 检查器形式化验证答案；此自学版未附带它。
  5. 每题注释中写明的运算次数上限是最终依据；若与 PDF 冲突，
     以本文件为准。

/*
 * 第 2 步：按照上述规则完成以下函数。
 * 
 * 为避免评分结果与预期不符：
 * 1. 使用 dlc 检查代码是否符合规则。
 * 2. 使用 btest 检查结果；原说明另提及 BDD 检查器，
 *    但它不在当前自学版中。
 */


#endif
//1
/* 
 * bitXor：仅使用 ~ 和 & 实现 x ^ y。
 * 示例：bitXor(4, 5) = 1
 * 可用运算符：~ &；最多 14 次；难度 1。
 */
int bitXor(int x, int y) {
  // 两个位不一样时才为1，先分成两种情况，再用德摩根定律把或换掉
  return ~((~(~x&y))&(~(~y&x)));
}
/* 
 * tmin：返回最小的 32 位二进制补码整数。
 * 可用运算符：! ~ & ^ | + << >>；最多 4 次；难度 1。
 */
int tmin(void) {
  return 1<<31;                 // 只有符号位是1，其余位都是0
}
//2
/*
 * isTmax：若 x 是最大的 32 位二进制补码整数则返回 1，否则返回 0。
 * 可用运算符：! ~ & ^ | +；最多 10 次；难度 1。
 */
int isTmax(int x) {
  int next=x+1;
  // 最大值加一等于它的按位取反，但-1也满足，所以还要排除next为0的情况
  return !(~x^next)&(!!next);
}
/* 
 * allOddBits：如果 x 中所有奇数编号的位都是 1，则返回 1。
 * 位编号从最低位 0 到最高位 31。
 * 示例：allOddBits(0xFFFFFFFD) = 0，allOddBits(0xAAAAAAAA) = 1。
 * 可用运算符：! ~ & ^ | + << >>；最多 12 次；难度 2。
 */
int allOddBits(int x) {
  int mask=0xAA;                // 10101010，一次拼8位，最后得到0xAAAAAAAA
  mask=(mask<<8)+0xAA;
  mask=(mask<<8)+0xAA;
  mask=(mask<<8)+0xAA;
  return !((mask|x)^x);         // 把奇数位全置1后还是x，说明这些位本来就是1
}
/* 
 * negate：返回 -x。
 * 示例：negate(1) = -1。
 * 可用运算符：! ~ & ^ | + << >>；最多 5 次；难度 2。
 */
int negate(int x) { 
  return ~x+1;                 // 补码取负就是取反加一，按32位看，二者相加为0
}
//3
/* 
 * isAsciiDigit：当 0x30 <= x <= 0x39 时返回 1，即 ASCII 数字 '0' 到 '9'。
 * 示例：0x35 返回 1；0x3a 和 0x05 返回 0。
 * 可用运算符：! ~ & ^ | + << >>；最多 15 次；难度 3。
 */
int isAsciiDigit(int x) { 
  int highOk=((x>>4)&1)&((x>>5)&1)&!((x>>6));  // 先检查是不是00000000 00000000 00000000 0011****
  int high=((x+6)>>4)&7;
  // 在0x30到0x3f里，加6后：低4位是0到9时high为3，是10到15时high为4
  return highOk&high;           // highOk只有0或1，刚好用high的最低位区分这两种情况
}
/* 
 * conditional：实现与 x ? y : z 相同的结果。
 * 示例：conditional(2, 4, 5) = 4。
 * 可用运算符：! ~ & ^ | + << >>；最多 16 次；难度 3。
 */
int conditional(int x, int y, int z) {
  int choice=!!x;
  choice=((choice<<31)>>31);    // 把0或1变成全0或全1，方便一次选出整个数
  return (choice&y)|(~choice&z);        // x非零选y，x为零选z
}
/* 
 * isLessOrEqual：若 x <= y 返回 1，否则返回 0。
 * 示例：isLessOrEqual(4, 5) = 1。
 * 可用运算符：! ~ & ^ | + << >>；最多 24 次；难度 3。
 */
int isLessOrEqual(int x, int y) {
  int sx = (x >> 31) & 1;       // 负数取1，非负数取0
  int sy = (y >> 31) & 1;
  int different = sx ^ sy;
  int subSign = (y + ~x + 1) >> 31;
  // 异号时x为负就成立；同号时y-x不会溢出，再看差是不是非负
  // 异号时算出来的subSign可能不可靠，但下面不会用它决定结果
  return (different & sx) | (!different & !subSign);
}
//4
/* 
 * logicalNeg：不使用 ! 运算符，实现与 !x 相同的结果。
 * 示例：logicalNeg(3) = 0，logicalNeg(0) = 1。
 * 可用运算符：~ & ^ | + << >>；最多 12 次；难度 4。
 */
int logicalNeg(int x) {
  int lowbit=(~x+1)&x;                 // 只留下最低位的1，x为0时还是0
  int nonzero=(((~lowbit+1)|lowbit)>>31)&1;
  // lowbit非零时，它和它的相反数至少有一个最高位为1，得到nonzero为1
  // 只有符号位是1的情况也成立，最后把0和1反过来
  return nonzero^1;
}
/* howManyBits：返回以二进制补码表示 x 所需的最少位数。
 * 示例：12 -> 5；298 -> 10；-5 -> 4；0 -> 1；-1 -> 1；
 *       0x80000000 -> 32。
 * 可用运算符：! ~ & ^ | + << >>；最多 90 次；难度 4。
 */
int howManyBits(int x) {
  int b16,b8,b4,b2,b1;
  int num=(x>>31)^x;            // 负数取反，非负数不变，这样都能找最高位的1
  int cnt=0;                   // 记录一共右移了多少位

  b16=((!!(num>>16))<<4);       // 高16位有1就右移16位，没有就不动，后面同理
  num=(num>>b16);
  cnt+=b16;

  b8=((!!(num>>8))<<3);
  num=(num>>b8);
  cnt+=b8;

  b4=((!!(num>>4))<<2);
  num=(num>>b4);
  cnt+=b4;

  b2=((!!(num>>2))<<1);
  num=(num>>b2);
  cnt+=b2;

  b1=(!!(num>>1));
  num=num>>b1;
  cnt+=b1;

  // num最后只剩0或1，加上它本身的位数，再加一位符号位
  // 原来的x是0或-1时，num和cnt都是0，结果正好为1
  return num+cnt+1;
}
//float
/* 
 * floatScale2：返回单精度浮点数 2*f 的位表示。
 * 参数和返回值都是 unsigned，但应按单精度浮点数的位表示解释。
 * 若输入是 NaN，原样返回输入。
 * 可用：任意整数/unsigned 运算（包括 ||、&&）及 if、while 等。
 * 最多 30 次运算；难度 4。
 */
unsigned floatScale2(unsigned uf) {
  unsigned sign = uf & 0x80000000u;
  unsigned exp = uf & 0x7f800000u;    // 阶码还在原来的位置，没有右移
  unsigned frac = uf & 0x007fffffu;
  if (exp == 0x7f800000u)       // 阶码全为1，NaN和无穷大原样返回
    return uf;
  if (exp == 0)                // 零和非规格化数，尾数左移，进位后也能自然变成规格化数
    return sign | (frac << 1);
  exp = exp + 0x00800000u;      // 规格化数乘2，阶码加一，也就是加1<<23
  if (exp == 0x7f800000u)       // 上溢时只留下符号和阶码，尾数不能带过去，否则会变成NaN
    return sign | exp;
  return sign | exp | frac;
}
/* 
 * floatFloat2Int：返回将单精度浮点数 f 转为 int 后的结果。
 * 参数 uf 是 f 的位表示，类型为 unsigned。
 * 超出 int 范围（包括 NaN 和无穷大）时返回 0x80000000u。
 * 可用：任意整数/unsigned 运算（包括 ||、&&）及 if、while 等。
 * 最多 30 次运算；难度 4。
 */
int floatFloat2Int(unsigned uf) {
  int signBit=(1u<<31);         // 符号位掩码，也是超出范围时要返回的位表示
  int exp=((((signBit>>8)^signBit)&uf)>>23);    // signBit是int，算术右移后可拼出阶码掩码
  unsigned positive=!(signBit&uf);             // 注意这里反了一下：符号位为0时positive为1
  unsigned frac=~(signBit>>8)&uf;              // 取出低23位的尾数
  if(uf==0||uf==signBit)        // 正零和负零都返回0
    return 0;
  exp-=127;                    // 减去偏置，得到实际指数
  // NaN和无穷大也会进这里；-2^31虽然合法，返回的位表示恰好也是signBit
  if(exp>=31)
    return signBit;
  frac+=(1<<23);               // 补上规格化数隐含的1；非规格化数会在下面直接返回0
  if(exp<0)
    return 0;                  // 绝对值小于1，向零截断后都是0
  if(exp<=23)
    frac=(frac>>(23-exp));     // 丢掉小数部分，不是四舍五入
  else
    frac=frac<<(exp+~23+1);    // 实际指数大于23，左移exp-23位
  if(positive==0)
    frac=-frac;                // 先算大小，最后再处理负号
  return frac;
}
/* 
 * floatPower2：返回单精度浮点数 2.0^x 的位表示，x 可为任意 32 位整数。
 * 返回值类型为 unsigned。若结果小到连非规格化数都无法表示，则返回 0；
 * 若结果过大，则返回正无穷大的位表示。
 * 可用：任意整数/unsigned 运算（包括 ||、&&）及 if、while 等。
 * 最多 30 次运算；难度 4。
 */
unsigned floatPower2(int x) {
  if(x>127){                      // 上溢，返回正无穷大
    int inf=((1<<31)>>8)^(1<<31);  // 阶码全为1，符号位和尾数全为0
    return inf;
  }
  else if(x>=-126)                // 规格化数，指数加上127的偏置，尾数为0
    return (x+127)<<23;
  else if(x>=-149)
    return 1<<(x+149);            // 非规格化数的最低位代表2^-149，按x往左挪这个1
  else
    return 0;                    // 比2^-149还小，无法表示，返回0
  return 2;                      // 前面的分支已经覆盖全部情况，这句不会执行
}
