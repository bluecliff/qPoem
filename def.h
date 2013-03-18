/**
 * @file def.h
 * @brief	基本变量和全局变量以及全局函数的生命和定义
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-10-05
 */

#ifndef DEF_H_
#define DEF_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned short int ushort;
typedef unsigned char uchar;

using namespace std;
/**
 * @brief	词库包含词的数目	
 */
#define num_word 2020

/**
 * @brief	构成待选词词表的词的数目
 */
#define word_least 300

/**
 * @brief	词的id为[0,split_one]之间时，词的长度为1
 */
#define split_one 825
/**
 * @brief	词的id为(split_one,split_two]之间时，词的长度为2
 */
#define split_two 2019

/**
 * @brief	reva.data文件的路径
 */
#define reva_data_path ".\\AppData\\QPoem\\reva.data"
/**
 * @brief	wordslib.data文件的路径
 */
#define wordslib_data_path ".\\AppData\\QPoem\\wordslib.data"


/**
 * @brief	基本词的结构
			pz是与词对应的平仄，为字符串，0，1，*，对应平仄通
			yj韵脚是1-14之间的整数，用uchar类型表示，对应14个现代韵脚
			cx词性，对应12个词性分类，有的词有可划入多个词性分类中，所以采用一个short int型表示，
			若为0,表示词性未知。该short int的0到11位分别对应11个词性分类，若该位为1，则词具有该位对应的词性
			qg情感分量，为0-7的整数，0表示该词的情感分量值未知，1-7分别表示情感的由低到高的7个分量
 */
struct word
{
  ushort id;    //词语编号
  char pz[2];     //平仄
  uchar yj;        //韵脚
  uchar cx;         //词性
  char qg;     //情感
};
typedef word *pword;

/**
 * @brief	词牌基本数据结构
 */
struct cipai
{
		/**
		 * @brief	该词牌对应宋词的句子数目
		 */
	int length;
	/**
	 * @brief	指向对应词牌的格律表
	 */
	char** ref;
};

char* cipai1[]={"*1/00","*0/*1/00/1","*0/*1","*1/00/1","*1/*0","*1/00/1","*/*1","*0/*1","*1/0/01"};
char* cipai2[]={"11/00/1/10","00/11/1/00","00/11/00/1","11/00/1/10","0/11","1/00","00/11/1/00","00/11/00/1","11/00/11/0"};
char* cipai3[]={"00/11/1/00","1/00","1/00","11/00","11/1/00","11/00/0/11","0/11","1/00","00/11/1/00",
				"1/00","1/00","11/00","11/1/00","11/00/0/11","0/11","1/00"};
char* cipai4[]={"**/0","1*/0","*1/00/*/10","*0/*1/0","1/*0","1/*0","*1/00/*/10","*0/*/10"};
char* cipai5[]={"*1/1/00","*1/00","*0/*1/1/00","*1/*0/0/11","*1/00","*1/1/00","*1/00","*0/*1/1/00","*1/*0/0/11","*1/00"};
char* cipai6[]={"*1/*0/0/11","*1/00","*1/0/01","*1/*0/0/11","*0/*1/0/01","*1/*0/0/11","*1/00","*1/00/1","*1/*0/01/1","*0/*1/00/1"};
char* cipai7[]={"*1/00/1/10","*0/*1/1/00","*0/*1/1/00","*1/*0/0/11","*0/*1/1/00","*0/*1/1/00"};
char* cipai8[]={"*0/*1/0/01","1/*1/0/01","*1/*0/0/11","*0/*1","*0/*1","*1/00/1","*0/*1/0/01",
				"*1/00/1/01","*1/*0/0/11","10/*1","*0/*1","*1/00/1"};
char* cipai9[]={"*0/*1","*1/0/01","*1/*0/0/11","*1/*0/*1","*0/*1/00","*0/*1/00","*1/*0/*1","*0/*1/00"};
char* cipai10[]={"*1/*0/*1","*0/*1/00","*0/*1/1/00","*1/*0/*1","*1/*0/*1","*0/*1/00","*0/*1/1/00","*1/*0/*1"};

/**
 * @brief	词牌表，指向每一个词牌的对应的词牌结构	
 */
cipai cipai_table[10]={
		{9,cipai1},
		{9,cipai2},
		{16,cipai3},
		{8,cipai4},
		{10,cipai5},
		{10,cipai6},
		{6,cipai7},
		{12,cipai8},
		{8,cipai9},
		{8,cipai10}
	};

/**
 * @brief	获取任意两个词的对应的相关度值
 *
 * @param	id1	词1的ID
 * @param	id2	词2的ID
 * @param	fin	reva.data文件输入流
 *
 * @return	返回词1和词2的相关度
 */
float get_re_value(int id1,int id2,ifstream &fin)
{
    if(fin && id1<num_word && id2<num_word)
    {
        float ret;
        int offset=(id1*num_word+id2)*4;
        fin.seekg(offset,ios::beg);
        fin.read((char*)&ret,4);
        return ret;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief	由词的ID获取相应词的具体信息
 *
 * @param	id	词的ID
 * @param	fin	wordslib.data文件的二进制输入流
 *
 * @return	获取得到的词的
 */
word get_word(int id,ifstream &fin)
{
    word w;
    if(fin && id<num_word)
    {

        fin.seekg(id*sizeof(word),ios::beg);
        fin.read((char*)&w,sizeof(word));
        return w;
    }
    return w;
}
#endif
