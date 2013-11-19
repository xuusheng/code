#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>
#define MAX_COLUMN_LEN    32
int main(int argc , char *argv[])
{
     MYSQL my_connection;
     MYSQL_RES *result;
     MYSQL_ROW sql_row;
     MYSQL_FIELD *fd;
     char column[MAX_COLUMN_LEN][MAX_COLUMN_LEN];
     int res;
     mysql_init(&my_connection);
     if (mysql_real_connect(&my_connection,"127.0.0.1","root","loongson","dev", 3306, NULL, 0))
     {
	  mysql_set_character_set(&my_connection, "utf8");
	  char my_query[1024];
	  bzero(my_query, sizeof(my_query));
	  sprintf(my_query, "select dsp from hf where id = '%s'", argv[1]);

	  res = mysql_query(&my_connection, my_query);//查询
	  if(!res)
	  {
	       result = mysql_store_result(&my_connection);//保存查询到的数据到result
	       if (result)
	       {
		    int i,j;

		    /*行数  printf("the result number is %lu\n ",(unsigned long)mysql_num_rows(result)); */

		    /* for(i = 0; fd = mysql_fetch_field(result); i++)//获取列名 */
		    /* { */
		    /* 	 bzero(column[i], sizeof(column[i])); */
		    /* 	 strcpy(column[i], fd->name); */
		    /* } */
		    j = mysql_num_fields(result);
		    /* for(i=0; i<j; i++) */
		    /* { */
		    /* 	 printf("%s\t", column[i]); */
		    /* } */
		    /* printf("\n"); */
		    while(sql_row = mysql_fetch_row(result))//获取具体的数据
		    {
			 for(i=0; i<j; i++)
			 {
			      printf("%s\t", sql_row[i]);
			 }
			 printf("\n");
		    }
               
	       }
	  }
	  else
	  {
	       perror("select");
	  }
     }
     else
     {
	  perror("connect:error");
     }
     mysql_free_result(result);//释放结果资源
     mysql_close(&my_connection);//断开连接
}
