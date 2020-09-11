#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone)
{
	NameCard* newcard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(newcard->name, name);
	strcpy(newcard->phone, phone);
	return newcard;
}

void ShowNameCardInfo(const NameCard & pcard)
{
	printf("[�̸�] : %s \n", pcard.name);
	printf("[��ȣ] : %s \n", pcard.phone);
}

int NameComp(const NameCard & pcard, const char* name)
{
	return strcmp(pcard.name, name)
}

void ChangePhoneNum(NameCard & pcard,const char* phone)
{
	strcpy(pcard.phone, phone);
}
