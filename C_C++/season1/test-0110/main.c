#define GandT 1000
void main(void)
{
	int i/*���[�v�@*/,b/*���[�v�A*/,sosuu[GandT]/*�f������p�z��*/;
	for(i = 0;i < GandT;++i)sosuu[i] = 0;//�S��������
	for(i = 1;i <= GandT ;++i)/*1�`GandT�܂ł̎҂�S�Ē��ׂ�*/{
		for(b = 2;b <= GandT;++b)/*������1�`GandT�܂�*/{
			if(i > b){//i��b���傫��������킴�킴�v�Z����K�v�Ȃ����
				if(i % b == 0)goto teso;/*���̐������̐��ȊO�̐��Ŋ��ꂽ��f������Ȃ��̂�goto�ō��J*/else if(i == b)goto z;//�܂�A�E�̏����ɓ��Ă͂܂�Ȃ�������f��������f�����Ƃ������Ƃ�m�点�Ă����ׂ�
			}else if(i == b)goto z; //�����ł��ǂ��������
		}
	goto teso;//�f�����ᖳ������
	z://�f���F��҂�
	sosuu[i - 1] = 1;//�f���F�� 
	teso://�f������Ȃ��z�̕��
	}
	for(i = 2;i <= GandT;++i)if(sosuu[i - 1] == 1)printf("%d\n",i);//�w����`��
}