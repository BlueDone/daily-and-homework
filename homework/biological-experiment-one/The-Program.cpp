# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std ; 

/// random number ///
struct timeb TimeSeed ; 
inline void random_initialization ( )
{
	ftime ( & TimeSeed ) ; 
	srand ( TimeSeed . time * 1000 + TimeSeed . millitm ) ; 
}
inline int random_num ( int l , int r )
{
	if ( l > r )
	{
		swap ( l , r ) ; 
	}
	int rdmnum = rand ( ) % ( r - l + 1 ) + l ; 
	return rdmnum ; 
}
/////*/ 

/// experiment ///
long long times = 0 ; 
char gamete = 'A' ; 
inline char get_gamete ( )
{
	int Probability = random_num ( 0 , 100 ) ; 
	if ( 0 <= Probability && Probability < 50 ) 
	{
		return toupper ( gamete ) ; 
	}
	else if ( 50 <= Probability && Probability <= 100 )
	{
		return tolower ( gamete ) ; 
	}
}
/////*/

int main ( )
{
	random_initialization ( ) ; 
	
	printf ( "请问需要进行几次配对?\n" ) ; 
	printf ( "(使用键盘输入,完成后回车确认)\n" ) ; 
	scanf ( "%lld" , &times ) ; 
	
	while ( times <= 0 )
	{
		printf ( "%lld 是一个无效的数字,请重新输入\n" , times ) ; 
		scanf ( "%lld" , &times ) ; 
	}
	
	printf ( "默认使用 A 和 a 表示遗传因子。\n" ) ; 
	
	char father ; 
	char mother ; 
	long long Purebred_Recessive = 0 ,
			  Hybrid_Dominant = 0 , 
			  Purebred_Dominant = 0 ;
	for ( long long i = 1 ; i <= times ; i ++ )
	{
		father = get_gamete ( ) ; 
		mother = get_gamete ( ) ; 
		
		/*/ DEBUG //
		printf ( "==%c%c==\n" , father , mother ) ; 
		///*/
		
		if ( father == tolower ( gamete ) && mother == tolower ( gamete ) )
		{
			printf ( "第 %lld 次配对得到的结果是 %c%c ，为纯合子，隐性。\n" , i , tolower ( gamete ) , tolower ( gamete ) ) ; 
			++ Purebred_Recessive ;
		}
		else if ( father == toupper ( gamete ) && mother == tolower ( gamete ) )
		{
			printf ( "第 %lld 次配对得到的结果是 %c%c ，为杂合子，显性。\n" , i , toupper ( gamete ) , tolower ( gamete ) ) ; 
			++ Hybrid_Dominant ; 
		}
		else if ( father == tolower ( gamete ) && mother == toupper ( gamete ) )
		{
			printf ( "第 %lld 次配对得到的结果是 %c%c ，为杂合子，显性。\n" , i , toupper ( gamete ) , tolower ( gamete ) ) ; 
			++ Hybrid_Dominant ; 
		}
		else if ( father == toupper ( gamete ) && mother == toupper ( gamete ) )
		{
			printf ( "第 %lld 次配对得到的结果是 %c%c ，为纯合子，显性。\n" , i , toupper ( gamete ) , toupper ( gamete ) ) ; 
			++ Purebred_Dominant ; 
		}
	}
	
	printf ( "\n结束了实验后，我们得到了:\n" ) ; 
	printf ( "组合为 %c%c 的有 %lld 个，占总数的 %.2Lf%%；\n" , tolower ( gamete ) , tolower ( gamete ) , Purebred_Recessive , ( long double ) Purebred_Recessive / times * 100 ) ; 
	printf ( "组合为 %c%c 的有 %lld 个，占总数的 %.2Lf%%；\n" , toupper ( gamete ) , tolower ( gamete ) , Hybrid_Dominant , ( long double ) Hybrid_Dominant / times * 100) ; 
	printf ( "组合为 %c%c 的有 %lld 个，占总数的 %.2Lf%%。\n" , toupper ( gamete ) , toupper ( gamete ) , Purebred_Dominant , ( long double ) Purebred_Dominant / times * 100) ; 
	
	return 0 ; 
} 
