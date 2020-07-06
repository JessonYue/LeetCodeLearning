extern int staticShared;
extern int dynshare;
int inner=10;

int funInner(){
}
int main(){
	int a=100;
	a = inner;
	funStaticShared();
	funDynShare();
	funInner();
}