/**
 * @file def.h
 * @brief	����������ȫ�ֱ����Լ�ȫ�ֺ����������Ͷ���
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
 * @brief	�ʿ�����ʵ���Ŀ	
 */
#define num_word 2020

/**
 * @brief	���ɴ�ѡ�ʴʱ�Ĵʵ���Ŀ
 */
#define word_least 300

/**
 * @brief	�ʵ�idΪ[0,split_one]֮��ʱ���ʵĳ���Ϊ1
 */
#define split_one 825
/**
 * @brief	�ʵ�idΪ(split_one,split_two]֮��ʱ���ʵĳ���Ϊ2
 */
#define split_two 2019

/**
 * @brief	reva.data�ļ���·��
 */
#define reva_data_path ".\\AppData\\QPoem\\reva.data"
/**
 * @brief	wordslib.data�ļ���·��
 */
#define wordslib_data_path ".\\AppData\\QPoem\\wordslib.data"


/**
 * @brief	�����ʵĽṹ
			pz����ʶ�Ӧ��ƽ�ƣ�Ϊ�ַ�����0��1��*����Ӧƽ��ͨ
			yj�Ͻ���1-14֮�����������uchar���ͱ�ʾ����Ӧ14���ִ��Ͻ�
			cx���ԣ���Ӧ12�����Է��࣬�еĴ��пɻ��������Է����У����Բ���һ��short int�ͱ�ʾ��
			��Ϊ0,��ʾ����δ֪����short int��0��11λ�ֱ��Ӧ11�����Է��࣬����λΪ1����ʾ��и�λ��Ӧ�Ĵ���
			qg��з�����Ϊ0-7��������0��ʾ�ôʵ���з���ֵδ֪��1-7�ֱ��ʾ��е��ɵ͵��ߵ�7������
 */
struct word
{
  ushort id;    //������
  char pz[2];     //ƽ��
  uchar yj;        //�Ͻ�
  uchar cx;         //����
  char qg;     //���
};
typedef word *pword;

/**
 * @brief	���ƻ������ݽṹ
 */
struct cipai
{
		/**
		 * @brief	�ô��ƶ�Ӧ�δʵľ�����Ŀ
		 */
	int length;
	/**
	 * @brief	ָ���Ӧ���Ƶĸ��ɱ�
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
 * @brief	���Ʊ�ָ��ÿһ�����ƵĶ�Ӧ�Ĵ��ƽṹ	
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
 * @brief	��ȡ���������ʵĶ�Ӧ����ض�ֵ
 *
 * @param	id1	��1��ID
 * @param	id2	��2��ID
 * @param	fin	reva.data�ļ�������
 *
 * @return	���ش�1�ʹ�2����ض�
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
 * @brief	�ɴʵ�ID��ȡ��Ӧ�ʵľ�����Ϣ
 *
 * @param	id	�ʵ�ID
 * @param	fin	wordslib.data�ļ��Ķ�����������
 *
 * @return	��ȡ�õ��Ĵʵ�
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
