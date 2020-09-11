#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { NAME_LEN = 30, PHONE_LEN = 30 };

struct NameCard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
};

NameCard* MakeNameCard(char* name, char* phone);
void ShowNameCardInfo(const NameCard& pcard);
int NameComp(const NameCard& pcard,const char* name);
void ChangePhoneNum(NameCard& pcard,const char* phone);



