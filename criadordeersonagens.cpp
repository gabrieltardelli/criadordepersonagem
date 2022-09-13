/*Universidade de Brasília
Projeto Computacional de AED

---------------Criador De Personagens D&D 5 Versão Espiões-----------------------

Criado por Gabriel Tardelli

Objetivos: O presente projeto busca auxiliar e organizar a criação de personagens
em um RPG de espiões. Esta é uma parte complexa, mas de suma importância num jogo de RPG.
A grande quantidade de informações muito particulares e as formas como elas devem ser
organizadas, classificadas e utilizadas, tornam este projeto especialmente prático.

*/

#include<locale.h>
#include<vector>
#include <set>
#include <list>
#include<fstream>
#include <time.h>
#include<iostream>
#include<windows.h>
#include <algorithm>
using namespace std;

//------------------------Set de Métodos e Classes------------------------------

//Ordenação: insertionsort
	void insertionsort(std::vector<int> &v){
		int i, j, toInsert;
		for(i = 1; i < v.size(); i++){
			toInsert = v[i]; //elemento a inserir
			j = i;
			while (toInsert < v[j-1] && j > 0){ //procura onde inserir
			    v[j] = v[j-1];
				j--;
			}
			v[j] = toInsert;
		}
	}

//Printador Vetores:
	void vetor (vector<string> x){
    	vector<string>::iterator p;
    	for (p=x.begin();p!=x.end();p++){
		cout<<*p<<", ";}
	}

	void Vetor (vector<string> x){
    	vector<string>::iterator p;
    	for (p=x.begin();p!=x.end();p++){
		cout<<*p;}
	}

	void vetors (vector<int> x){
    	vector<int>::iterator p;
    	for (p=x.begin();p!=x.end();p++){
		cout<<*p<<", ";}
	}
//Classe Personagem
//Esta inicia o(s) objeto(s) do(s) personagens
	class Personagem{
		//Atributos
		string is;
		string acao;
		string nome;
		string classe;
		string saving;
		string armadura;
		string habilidade;

		list<string> armas;
		set <string> skills;
		list<string>equipamentos;
		list<string>vazia;

		int sexo;
		int mangos;
		int hitpoints;
		int armorclass;
		int forca;int dest;int Const;int inte;int sabedoria;int carisma;
		int mforca;int mdest;int mConst;int minte;int msabedoria;int mcarisma;

		public:
			//Construtor
			Personagem(string arma, int AC,string c,int s,string n,string si,int m,list<string>e,int hp,string he,list<string>ar,string ac,string sav,set<string>sk,int fo,int de,int co,int in,int sa,int ca,int mfo,int mde,int mco,int min,int msa,int mca){

			is=si;
			sexo=s;
			nome=n;
			acao=ac;
			dest=de;
			inte=in;
			classe=c;
			Const=co;
			mangos=m;
			armas=ar;
			forca=fo;
			mdest=mde;
			skills=sk;
			minte=min;
			saving=sav;
			carisma=ca;
			mforca=mfo;
			mConst=mco;
			sabedoria=sa;
			hitpoints=hp;
			mcarisma=mca;
			habilidade=he;
			armadura=arma;
			armorclass=AC;
			msabedoria=msa;
			equipamentos=e;
		}

		//Método Resumo dos Objetos do(s) personagen(s), exibe o perfil do personagem.
    	void resumo(void){
			cout << " Agora pegue um lápis e um papel e anote a ficha de seu personagem\n\n\n";

		if(sexo==0){
			cout << " Nome do agente: " <<nome<< " \nIdentidade secreta: "<< is <<endl;
		}

		else{
			cout<<"Nome da agente: "<<nome<<"\nIdentidade secreta: "<<is<<endl;
		}

		cout << " Classe: " << classe << endl;
		cout << " Hit-points: " << hitpoints << endl;
		cout << " Dinheiro local: " << mangos <<"\n";
		cout << " Armor class: " << armorclass << " ("<<armadura<<")\n";
		cout << " Habilidade especial: " << habilidade << endl;
		cout << " Armas de seu arsenal: ";

		while(!armas.empty()){
	    cout<<armas.front()<<", ";
	    vazia.push_back(armas.front());
	    armas.pop_front();
	  }
	  swap(vazia, armas);
		cout << endl;

		cout << " Equipamentos: ";
		while(!equipamentos.empty()){
			cout<<equipamentos.front()<<", ";
			vazia.push_back(equipamentos.front());
			equipamentos.pop_front();
		}
		swap(vazia, equipamentos);
		cout << endl;

		cout << " Ação proficiente: " << acao << endl;
		cout << " Proficiência em saving throw: "<< saving << endl;
		cout << " Bônus de proficiência: 2\n";
		cout << " Iniciativa: " << mdest << endl;
		cout << " Deslocamento: 10 metros\n";
		cout << " Skills: ";

	    for(set<string>::iterator it=skills.begin(); it!=skills.end(); it++) {
			cout<<*it<<", ";
		}
		cout<<endl;

		cout << " Atributos e seus modificadores-\nForça: "<<forca<<" ("<<mforca<<")\nDestreza: "<<dest<<" ("<<mdest<<")\nConstituição: "<<Const<<" ("<<mConst<<")\nInteligência: "<<inte<<" ("<<minte<<")\nSabedoria: "<<sabedoria<<" ("<<msabedoria<<")\nCarisma: "<<carisma<<" ("<<mcarisma<<")";
		cout << " \n\nBoa jogatina agente\n\n";}
	};

//Metodo modificador, serve como auxiliar do dado
	int modificador (int x){
		if(x==1)
		    return -5;

		if ((x==2)||(x==3))
		    return -4;

		if ((x==4)||(x==5))
		    return -3;

		if ((x==6)||(x==7))
		    return -2;

		if ((x==8)||(x==9))
		    return -1;

		if ((x==10)||(x==11))
		    return 0;

		if ((x==12)||(x==13))
		    return 1;

		if ((x==14)||(x==15))
		    return 2;

		if ((x==16)||(x==17))
		    return 3;

		if ((x==18)||(x==19))
		    return 4;

		if ((x==20)||(x==21))
	  	  return 5;
	}

//---------------------------------Main-----------------------------------------

int main(){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));

//-----------------------Set de variáveis da main-------------------------------

	string si;
	string acao;
	string name;
	string classe;
	string saving;
	string armadura;
	string habilidades;

	list<string>armas;
	set <string>skills;
	list<string>equipamentos;
	list<string>vazia;

	int sexo;
	int hpclasse;
	int hitpoints;
	int armorclass;
	int mangos=2000;
	int forca=0;int dest=0;int Const=0;int inte=0;int sabedoria=0;int carisma=0;
	int mforca=0;int mdest=0;int mConst=0;int minte=0;int msabedoria=0;int mcarisma=0;
	int jaacrobacia=0;int jadiplomacia=0;int jacultura=0;int jaatletica=0;int jahistoria=0;int jainsight=0;int jaintimidacao=0;int jainvestigacao=0;int jamedicina=0;int jatecnologia=0;int japercepcao=0;int japerformance=0;int japersuasao=0;int jadesculpas=0;int jamimetagem=0;int jastealth=0;int jasobrevivencia=0;

//-------------------Inicio do menu e das operações para receber as informações do usuário----------------------

	cout<<"Bem-vindo ao criador de personagem da versão adaptada do D&D 5 para espiões\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");

//-------------------Definindo nome, identidade e sexo--------------------------

	cout<<"Primeiramente defina o nome do seu espião, sua identidade secreta e o sexo\n";
	cout<<"Nome(Exe: 007): ";
	//cin>>name;
	getline (cin,name);

	cout<<" Identidade secreta(Exe: James Bond): ";
	getline (cin,si);
	//cin>>si;

	Sexo:
	cout<<" Aperte (0) para ser um homem ou (1) para ser mulher\n";
	cin>>sexo;
	if((sexo==0) || (sexo==1))
	cout<<" ";
	else
	goto Sexo;
	system("cls");

//---------------------------Definindo classe-----------------------------------

	cout<<" Muito bem, agora vamos escolher uma classe para "<<name<<endl;
	cout<<"(0)Descrição das classes\n(1)Brucutu\n(2)Oculto\n(3)Tanque\n(4)Agente Tech\n(5)Sábio\n(6)Galã\nNúmero da classe: ";

	int numclasse;
	classchoose:
	cin>>numclasse;
	if(numclasse==0)
	system("start https://drive.google.com/file/d/1wOstJsgfvwwZlWoW6y8JzOWvM60sIb2p/view");

	if((numclasse==1)||(numclasse==2)||(numclasse==3)||(numclasse==4)||(numclasse==5)||(numclasse==6))
	cout<<" ";

	else{
		cout<<"Número digitado não corresponde a nenhuma classe\nNúmero da classe: ";
		goto classchoose;
	}
	cout<<endl;

	//Caso Burucutu Homem
	if((numclasse==1)&&(sexo==0)){

		cout<<name<<" será um agente Brucutu";
		classe="Brucutu";
		mforca=1;
		minte=-1;
		hpclasse=12;
		jaintimidacao=1;
		jaatletica=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("intimidação");
		skills.insert("atlética");
		equipamentos.push_back("canivete suíço");
		acao="Interrogatório";
		saving="força e constituição";
		habilidades="Músculos e mais músculos: ganhe +2 de carisma ao dialogar com sexo oposto e +2 de força ao entrar em combate mão a mão";
	}

	//Caso Agente Oculto Homem
	if((numclasse==2)&&(sexo==0)){

		cout<<name<<" será um agente Oculto";
		classe="Oculto";
		mdest=1;
		mConst=-1;
		hpclasse=6;
		jaacrobacia=1;
		jastealth=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("acrobáctica");
		skills.insert("stealth");
		equipamentos.push_back("corta-vidro");
		acao="Abrir fechaduras complexas";
		saving="destreza e inteligência";
		habilidades="First!: Seja sempre o primeiro em rodadas de ataque";
	}

	//Caso Agente Tanque Homem
	if((numclasse==3)&&(sexo==0)){

		cout<<name<<" será um agente Tanque";
		classe="Tanque";
		mConst=1;
		minte=-1;
		hpclasse=12;
		jaintimidacao=1;
		jasobrevivencia=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("intimidação");
		skills.insert("sobrevivência");
		equipamentos.push_back("colete a prova de bala");
		acao="Recarregamento automático";
		saving="constituição e força";
		habilidades="Imortal: ao morrer pela primeira vez, volte a 25% de seu hp original, exceto morte por explosão";
	}

	//Caso Agente Tech Homem
	if((numclasse==4)&&(sexo==0)){

		cout<<name<<" será um agente Tech";
		classe="Agente Tech";
		minte=1;
		mcarisma=-1;
		hpclasse=10;
		jatecnologia=1;
		jainvestigacao=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("tecnologia");
		skills.insert("investigação");
		equipamentos.push_back("falsificador de documentos");
		acao="decriptar códigos";
		saving="inteligência e sabedoria";
		habilidades="Autodidata mecânico: gaste 2 rounds para descobrir tudo sobre uma tecnologia desconhecida ao encontra-la";
	}

	//Caso Agente Sabio Homem
	if((numclasse==5)&&(sexo==0)){

		cout<<name<<" será um agente Sábio";
		classe="Sábio";
		msabedoria=2;
		mforca=-1;
		hpclasse=8;
		jahistoria=1;
		jainsight=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("história");
		skills.insert("artes marciais");
		equipamentos.push_back("mapas");
		acao="Leitura rápida";
		saving="sabedoria e inteligência";
		habilidades="Sabedoria opressora:  Jogue dois d20 e some ao tentar conseguir informação de alguém com sabedoria menor que a sua";
	}

	//Caso Galã Homem
	if((numclasse==6)&&(sexo==0)){

		classe="Galã";
		mcarisma=2;
		msabedoria=-1;
		hpclasse=10;
		cout<<name<<" será um agente Galã";
		japersuasao=1;
		jainvestigacao=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("persuasão");
		skills.insert("investigação");
		equipamentos.push_back("boa-noite");
		acao="Conseguir aliados";
		saving="carisma e sabedoria";
		habilidades="Garanhão: ganhe +2 de carisma ao dialogar com o sexo oposto e se tirar 1 no dado, jogue de novo";
	}

	//Caso Burucutu Mulher
	if((numclasse==1)&&(sexo==1)){

		cout<<name<<" será uma agente Brucutu";
		classe="Brucutu";
		mforca=1;
		minte=-1;
		hpclasse=12;
		jaintimidacao=1;
		jaatletica=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("intimidação");
		skills.insert("atlética");
		equipamentos.push_back("canivete suíço");
		acao="Interrogatório";
		saving="força e constituição";
		habilidades="Músculos e mais músculos: ganhe +2 de carisma ao dialogar com sexo oposto e +2 de força ao entrar em combate mão a mão";
	}

	//Caso Agente Oculto Mulher
	if((numclasse==2)&&(sexo==1)){

		cout<<name<<" será uma agente Oculta";
		classe="Oculto";
		mdest=1;
		mConst=-1;
		hpclasse=6;
		jaacrobacia=1;
		jastealth=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("acrobáctica");
		skills.insert("stealth");
		equipamentos.push_back("corta-vidro");
		acao="Abrir fechaduras complexas";
		saving="destreza e inteligência";
		habilidades="First!: Seja sempre o primeiro em rodadas de ataque";
	}

	//Caso Agente Tanque Mulher
	if((numclasse==3)&&(sexo==1)){

		cout<<name<<" será uma agente Tanque";
		classe="Tanque";
		mConst=1;
		minte=-1;
		hpclasse=12;
		jaintimidacao=1;
		jasobrevivencia=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("intimidação");
		skills.insert("sobrevivência");
		equipamentos.push_back("colete a prova de bala");
		acao="Recarregamento automático";
		saving="constituição e força";
		habilidades="Imortal: ao morrer pela primeira vez, volte a 25% de seu hp original, exceto morte por explosão";
	}

	//Caso Agente Tech mulher
	if((numclasse==4)&&(sexo==1)){

		cout<<name<<" será uma agente Tech";
		classe="Agente Tech";
		minte=1;
		mcarisma=-1;
		hpclasse=10;
		jatecnologia=1;
		jainvestigacao=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("tecnologia");
		skills.insert("investigação");
		equipamentos.push_back("falsificador de documentos");
		acao="decriptar códigos";
		saving="inteligência e sabedoria";
		habilidades="Autodidata mecânica: gaste 2 rounds para descobrir tudo sobre uma tecnologia desconhecida ao encontra-la";
	}

	//Caso Agente Sábia Mulher
	if((numclasse==5)&&(sexo==1)){

		cout<<name<<" será uma agente Sábia";
		classe="Sábio";
		msabedoria=1;
		mforca=-1;
		hpclasse=8;
		jahistoria=1;
		jainsight=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("história");
		skills.insert("artes marciais");
		equipamentos.push_back("mapas");
		acao="Leitura rápida";
		saving="sabedoria e inteligência";
		habilidades="Sabedoria opressora:  Jogue dois d20 e some ao tentar conseguir informação de alguém com sabedoria menor que a sua";
	}

	//Caso Agente Galã Mulher
	if((numclasse==6)&&(sexo==1)){

		cout<<name<<" será uma agente Galã";
		classe="Galã";
		mcarisma=1;
		msabedoria=-1;
		hpclasse=10;
		japersuasao=1;
		jainvestigacao=1;

		//De acordo com classe escolhida as skills são setadas dentro do vetor "skills"
		skills.insert("persuasão");
		skills.insert("investigação");
		equipamentos.push_back("boa-noite");
		acao="Conseguir aliados";
		saving="carisma e sabedoria";
		habilidades="Sensual: ganhe +2 de carisma ao dialogar com o sexo oposto e se tirar 1 no dado, jogue de novo";
	}
	cout<<endl<<endl<<endl;
	system("pause");
	system("cls");

//-------------------------Definindo Atributos Modificadores--------------------



/*Aqui serão definidos atributos como "Destreza" que não são predefinidos por classe,
nem diretamente definido por uma escolha DIRETA do usuário.
Dependem do rolar do dado.*/

	cout<<"Agora vamos definir seus atributos e seus modificadores\nQuem vai jogar os dados? (é necessário um d20)\n(1) eu jogo (2) o programa joga\n";
	int dadosjogador;
	vector<int>Dado;
	Dadoemcasa:
	int dadoemcasa;
	cin>>dadoemcasa;

	if ((dadoemcasa>1)&&(dadoemcasa<2)){
		cout<<"Digite 1 ou 2";
   	 goto Dadoemcasa;
	}

	else if (dadoemcasa==1){
    	cout<<"Ok, então você vai jogar os dados\nJogue e digite os números seguidos de espaço e quando terminar aperte Enter (Ex: 10 8 5 17 13 15)\nDigite 6 dados: ";
    	int afor=6;

		while(afor!=0){
    		cin>>dadosjogador;
    		Dado.push_back(dadosjogador);
    		afor--;
		}
	}

	else {
    	cout<<"Ok, então eu jogo os dados por você\nOs dados: ";
		int afor=6;

		while(afor!=0){
			int d20=rand()%13;
			d20=d20+5;
			Dado.push_back(d20);
			Sleep(1000);
			cout<<d20<<", ";
			afor--;
		}
		cout<<endl<<endl<<endl;
    	system("pause");
	}


	vector<int>::iterator P;
	vector<string>FORCA;vector<string>DESTREZA;vector<string>CONSTITUICAO;vector<string>INTELIGENCIA;vector<string>SABEDORIA;vector<string>CARISMA;
	FORCA.push_back("(1) Força\n");DESTREZA.push_back("(2) Destreza\n");CONSTITUICAO.push_back("(3) Constituição\n");INTELIGENCIA.push_back("(4) Inteligência\n");SABEDORIA.push_back("(5) Sabedoria\n");CARISMA.push_back("(6) Carisma\n");
	cout<<"\n";
	system("cls");
	int xatri;
	int backup;int backup2;
	vector<int>VOLTA;
	int jaforca=0;int jadest=0; int jaConst=0; int jainte=0;int jasabedoria=0;int jacarisma=0;
	while(Dado.empty()==0){
	xatri=VOLTA.size()-1;


	/*O dado do jogo é settado como um vetor que aramazena os resultados obtidos com
	as operações acima. Agora usamos o método InsertionSort para odena-lo de forma crescente*/

	insertionsort(Dado);
	system("cls");
	cout<<"Esses são seus dados em odem crescente: ";
	vetors(Dado);
	cout<<"\nAgora vamos atribuir os dados aos atributos";
	P=Dado.begin();
	cout<<"\nOnde você quer atribuir o "<<*P;
	backup2=*P;

	//cout<<"\n\n(1) Força\n(2) Destreza\n(3) Constituição\n(4) Inteligência\n(5) Sabedoria\n(6) Carisma\n\nNúmero do atributo: ";
	cout<<"\n(99) Voltar uma ação\n\n";Vetor(FORCA);Vetor(DESTREZA);Vetor(CONSTITUICAO);Vetor(INTELIGENCIA);Vetor(SABEDORIA);Vetor(CARISMA);
	escolheratributos:
	cout<<"\nNúmero do atributo: ";
	int atridado;
	cin>>atridado;

	//Aqui o método "modificador" é usado para settar os atribos
	if (atridado==99){
		xatri=VOLTA.size()-1;
		if (VOLTA[xatri]==1){jaforca--;mforca=mforca-modificador(forca);FORCA.clear();FORCA.push_back("(1) Força\n");Dado.push_back(backup2);Dado.push_back(backup);}
		if (VOLTA[xatri]==2){jadest--;mdest=mdest-modificador(dest);DESTREZA.clear();DESTREZA.push_back("(2) Destreza\n");Dado.push_back(backup2);Dado.push_back(backup);}
		if (VOLTA[xatri]==3){jaConst--;mConst=mConst-modificador(Const);CONSTITUICAO.clear();CONSTITUICAO.push_back("(3) Constituição\n");Dado.push_back(backup2);Dado.push_back(backup);}
		if (VOLTA[xatri]==4){jainte--;minte=minte-modificador(inte);INTELIGENCIA.clear();INTELIGENCIA.push_back("(4) Inteligência\n");Dado.push_back(backup2);Dado.push_back(backup);}
		if (VOLTA[xatri]==5){jasabedoria--;msabedoria=msabedoria-modificador(sabedoria);SABEDORIA.clear();SABEDORIA.push_back("(5) Sabedoria\n");Dado.push_back(backup2);Dado.push_back(backup);}
		if (VOLTA[xatri]==6){jacarisma--;mcarisma=mcarisma-modificador(carisma);CARISMA.clear();CARISMA.push_back("(6) Carisma\n");Dado.push_back(backup2);Dado.push_back(backup);}
	}

	if(atridado==1){
		if(jaforca==1){
		    cout<<"Você já escolheu força";
			goto escolheratributos;
		}

    	forca=*P;
    	backup=*P;
    	mforca=mforca+modificador(forca);
   		FORCA.clear();
    	FORCA.push_back("(1) Já foi escolhido\n");
		jaforca++;
		VOLTA.push_back(atridado);
	}

	if(atridado==2){
		if(jadest==1){
	  	  cout<<"Você já escolheu destreza";
			goto escolheratributos;
		}

    	dest=*P;
    	backup=*P;
   		mdest=modificador(dest)+mdest;
    	DESTREZA.clear();
    	DESTREZA.push_back("(2) Já foi escolhido\n");
		jadest++;
		VOLTA.push_back(atridado);
	}

	if(atridado==3){
		if(jaConst==1){
	 	   cout<<"Você já escolheu constituição";
			goto escolheratributos;
		}

    	Const=*P;
    	backup=*P;
    	mConst=mConst+modificador(Const);
    	CONSTITUICAO.clear();
    	CONSTITUICAO.push_back("(3) Já foi escolhido\n");
		jaConst++;
		VOLTA.push_back(atridado);
	}

	if(atridado==4){
		if(jainte==1){
	 	   cout<<"Você já escolheu inteligência";
			goto escolheratributos;
		}

    	inte=*P;
    	backup=*P;
   		minte=minte+modificador(inte);
    	INTELIGENCIA.clear();
    	INTELIGENCIA.push_back("(4) Já foi escolhido\n");
		jainte++;
		VOLTA.push_back(atridado);
	}

	if(atridado==5){
		if(jasabedoria==1){
		    cout<<"Você já escolheu sabedoria";
			goto escolheratributos;
		}

    	sabedoria=*P;
    	backup=*P;
   		msabedoria=msabedoria+modificador(sabedoria);
    	SABEDORIA.clear();
    	SABEDORIA.push_back("(5) Já foi escolhido\n");
		jasabedoria++;
		VOLTA.push_back(atridado);
	}

	if(atridado==6){
		if(jacarisma==1){
	 	   cout<<"Você já escolheu carisma";
			goto escolheratributos;
		}

    	carisma=*P;
    	backup=*P;
    	mcarisma=mcarisma+modificador(carisma);
    	CARISMA.clear();
    	CARISMA.push_back("(6) Já foi escolhido\n");
		jacarisma++;
		VOLTA.push_back(atridado);
	}

	Dado.erase(Dado.begin());
	if ((atridado==0) || (atridado==99) || (atridado==1) || (atridado==2) || (atridado==3) || (atridado==4) || (atridado==5) || (atridado==6))
    cout<<"";

	else{
		cout<<"Número digitado não corresponde a nenhum atributo";
    	goto escolheratributos;}
	}
	cout<<endl;
	system("pause");
	system("cls");

	//------------------------------------------------------------------------------
	/*Aqui são  definidos mais atributos do personagem*/


	cout<<"Vamos definir seus hitpoints\nNa sua classe ele é definido como "<<hpclasse<<" + seu modificador de constituição";
	hitpoints=hpclasse+mConst;
	cout<<"\nPor isso seu hp é "<<hitpoints<<"\n\n";
	system("pause");
	system("cls");

	int opskill;
	cout<<"Agora vamos escolher mais skills que seu agente será proficiente";
	cout<<"\nVocê já é proficiente em: ";
	vector<string>::iterator p;

    for(set<string>::iterator it=skills.begin(); it!=skills.end(); it++){
		cout<<*it<<", ";
	}

	cout<<"\nAinda faltam 3 skills pra escolher\n\n(0)  Acrobacia (DEX)\n(1)  Diplomacia(WIS)\n(2)  Cultura Local(INT)\n(3)  Atlética(STR)\n(4)  História(INT)\n(5)  Artes marciais(WIS)\n(6)  Intimidação(CHA)\n(7)  Investigação(INT)\n(8)  Medicina(WIS)\n(9)  Tecnologia(INT)\n(10) Percepção(WIS)\n(11) Performance(CHA)\n(12) Persuasão(CHA)\n(13) Desculpas rápidas(INT)\n(14) Mimetagem(DEX)\n(15) Stealth(DEX)\n(16) Sobrevivência(WIS)\n";
	firstchoice:
	cout<<"\nNúmero da skill: ";
	cin>>opskill;

	if(opskill==0){
		if (jaacrobacia!=0){
			cout<<"Você já escolheu acrobacia";
			goto firstchoice;
		}
		jaacrobacia++;
		skills.insert("acrobacia");
	}

	if(opskill==1){
		if (jadiplomacia!=0){
			cout<<"Você já escolheu diplomacia";
			goto firstchoice;
		}
		jadiplomacia++;
		skills.insert("Diplomacia");
	}

	if(opskill==2){
		if (jacultura!=0){
			cout<<"Você já escolheu cultura local";
			goto firstchoice;
		}
		jacultura++;
		skills.insert("Cultura local");
	}

	if(opskill==3){
		if (jaatletica!=0){
			cout<<"Você já escolheu atlética";
			goto firstchoice;
		}
		jaatletica++;
		skills.insert("atlética");
	}

	if(opskill==4){
		if (jahistoria!=0){
			cout<<"Você já escolheu história";
			goto firstchoice;
		}
		jahistoria++;
		skills.insert("história");
	}

	if(opskill==5){
		if (jainsight!=0){
			cout<<"Você já escolheu artes marciais";
			goto firstchoice;
		}
		jainsight++;
		skills.insert("artes marciais");
	}

	if(opskill==6){
		if (jaintimidacao!=0){
			cout<<"Você já escolheu intimidação";
			goto firstchoice;
		}
		jaintimidacao++;
		skills.insert("intimidação");
	}

	if(opskill==7){
		if (jainvestigacao!=0){
			cout<<"Você já escolheu investigação";
			goto firstchoice;
		}
		jainvestigacao++;
		skills.insert("investigação");
	}

	if(opskill==8){
		if (jamedicina!=0){
			cout<<"Você já escolheu medicina";
			goto firstchoice;
		}
		jamedicina++;
		skills.insert("medicina");
	}

	if(opskill==9){
		if (jatecnologia!=0){
			cout<<"Você já escolheu tecnologia";
			goto firstchoice;
		}
		jatecnologia++;
		skills.insert("tecnologia");
	}

	if(opskill==10){
		if (japercepcao!=0){
			cout<<"Você já escolheu percepção";
			goto firstchoice;
		}
		japercepcao++;
		skills.insert("percepção");
	}

	if(opskill==11){
		if (japerformance!=0){
			cout<<"Você já escolheu performance";
			goto firstchoice;
		}
		japerformance++;
		skills.insert("performance");
	}

	if(opskill==12){
		if (japersuasao!=0){
			cout<<"Você já escolheu persuasão";
			goto firstchoice;
		}
		japersuasao++;
		skills.insert("persuasão");
	}

	if(opskill==13){
		if (jadesculpas!=0){
			cout<<"Você já escolheu desculpas rápidas";
			goto firstchoice;
		}
		jadesculpas++;
		skills.insert("desculpas rápidas");
	}

	if(opskill==14){
		if (jamimetagem!=0){
			cout<<"Você já escolheu mimetagem";
			goto firstchoice;
		}
		jamimetagem++;
		skills.insert("mimetagem");
	}

	if(opskill==15){
		if (jastealth!=0){
			cout<<"Você já escolheu stealth";
			goto firstchoice;
		}
		jastealth++;
		skills.insert("stealth");
	}

	if(opskill==16){
		if (jasobrevivencia!=0){
			cout<<"Você já escolheu sobrevivência";
			goto firstchoice;
		}
		jasobrevivencia++;
		skills.insert("sobrevivência");
	}
	system("cls");
	cout<<"Você já é proficiente em: ";

	for(set<string>::iterator it=skills.begin(); it!=skills.end(); it++){
		cout<<*it<<", ";
	}


	cout<<"\nAinda faltam 2 skills pra escolher\n\n(0)  Acrobacia (DEX)\n(1)  Diplomacia(WIS)\n(2)  Cultura Local(INT)\n(3)  Atlética(STR)\n(4)  História(INT)\n(5)  Insight(WIS)\n(6)  Intimidação(CHA)\n(7)  Investigação(INT)\n(8)  Medicina(WIS)\n(9)  Tecnologia(INT)\n(10) Percepção(WIS)\n(11) Performance(CHA)\n(12) Persuasão(CHA)\n(13) Desculpas rápidas(INT)\n(14) Mimetagem(DEX)\n(15) Stealth(DEX)\n(16) Sobrevivência(WIS)\n";
	secondchoice:
	cout<<"\nNúmero da skill: ";
	cin>>opskill;

	if(opskill==0){
		if (jaacrobacia!=0){
			cout<<"Você já escolheu acrobacia";
			goto secondchoice;
		}
		jaacrobacia++;
		skills.insert("acrobacia");
	}

	if(opskill==1){
		if (jadiplomacia!=0){
			cout<<"Você já escolheu diplomacia";
			goto secondchoice;
		}
		jadiplomacia++;
		skills.insert("Diplomacia");
	}

	if(opskill==2){
		if (jacultura!=0){
			cout<<"Você já escolheu cultura local";
			goto secondchoice;
		}
		jacultura++;
		skills.insert("Cultura local");
	}

	if(opskill==3){
		if (jaatletica!=0){
			cout<<"Você já escolheu atlética";
			goto secondchoice;
		}
		jaatletica++;
		skills.insert("atlética");
	}

	if(opskill==4){
		if (jahistoria!=0){
			cout<<"Você já escolheu história";
			goto secondchoice;
		}
		jahistoria++;
		skills.insert("história");
	}

	if(opskill==5){
		if (jainsight!=0){
			cout<<"Você já escolheu artes marciais";
			goto secondchoice;
		}
		jainsight++;
		skills.insert("artes marciais");
	}

	if(opskill==6){
		if (jaintimidacao!=0){
			cout<<"Você já escolheu intimidação";
			goto secondchoice;
		}
		jaintimidacao++;
		skills.insert("intimidação");
	}

	if(opskill==7){
		if (jainvestigacao!=0){
			cout<<"Você já escolheu investigação";
			goto secondchoice;
		}
		jainvestigacao++;
		skills.insert("investigação");
	}

	if(opskill==8){
		if (jamedicina!=0){
			cout<<"Você já escolheu medicina";
			goto secondchoice;
		}
		jamedicina++;
		skills.insert("medicina");
	}

	if(opskill==9){
		if (jatecnologia!=0){
			cout<<"Você já escolheu tecnologia";
			goto secondchoice;
		}
		jatecnologia++;
		skills.insert("tecnologia");
	}

	if(opskill==10){
		if (japercepcao!=0){
			cout<<"Você já escolheu percepção";
			goto secondchoice;
		}
		japercepcao++;
		skills.insert("percepção");
	}

	if(opskill==11){
		if (japerformance!=0){
			cout<<"Você já escolheu performance";
			goto secondchoice;
		}
		japerformance++;
		skills.insert("performance");
	}

	if(opskill==12){
		if (japersuasao!=0){
			cout<<"Você já escolheu persuasão";
			goto secondchoice;
		}
		japersuasao++;
		skills.insert("persuasão");
	}

	if(opskill==13){
		if (jadesculpas!=0){
			cout<<"Você já escolheu desculpas rápidas";
			goto secondchoice;
		}
		jadesculpas++;
		skills.insert("desculpas rápidas");
	}

	if(opskill==14){
		if (jamimetagem!=0){
			cout<<"Você já escolheu mimetagem";
			goto secondchoice;
		}
		jamimetagem++;
		skills.insert("mimetagem");
	}

	if(opskill==15){
		if (jastealth!=0){
			cout<<"Você já escolheu stealth";
			goto secondchoice;
		}
		jastealth++;
		skills.insert("stealth");
	}

	if(opskill==16){
		if (jasobrevivencia!=0){
			cout<<"Você já escolheu sobrevivência";
			goto secondchoice;
		}
		jasobrevivencia++;
		skills.insert("sobrevivência");
	}

	system("cls");
	cout<<"Você já é proficiente em: ";

	for(set<string>::iterator it=skills.begin(); it!=skills.end(); it++){
		cout<<*it<<", ";
	}

	cout<<"\nAinda falta 1 skill pra escolher\n\n(0)  Acrobacia (DEX)\n(1)  Diplomacia(WIS)\n(2)  Cultura Local(INT)\n(3)  Atlética(STR)\n(4)  História(INT)\n(5)  Insight(WIS)\n(6)  Intimidação(CHA)\n(7)  Investigação(INT)\n(8)  Medicina(WIS)\n(9)  Tecnologia(INT)\n(10) Percepção(WIS)\n(11) Performance(CHA)\n(12) Persuasão(CHA)\n(13) Desculpas rápidas(INT)\n(14) Mimetagem(DEX)\n(15) Stealth(DEX)\n(16) Sobrevivência(WIS)\n";
	tirdchoice:
	cout<<"\nNúmero da skill: ";
	cin>>opskill;

	if(opskill==0){
		if (jaacrobacia!=0){
			cout<<"Você já escolheu acrobacia";
			goto tirdchoice;
		}
		jaacrobacia++;
		skills.insert("acrobacia");
	}

	if(opskill==1){
		if (jadiplomacia!=0){
			cout<<"Você já escolheu diplomacia";
			goto tirdchoice;
		}
		jadiplomacia++;
		skills.insert("Diplomacia");
	}

	if(opskill==2){
		if (jacultura!=0){
			cout<<"Você já escolheu cultura local";
			goto tirdchoice;
		}
		jacultura++;
		skills.insert("Cultura local");
	}

	if(opskill==3){
		if (jaatletica!=0){
			cout<<"Você já escolheu atlética";
			goto tirdchoice;
		}
		jaatletica++;
		skills.insert("atlética");
	}

	if(opskill==4){
		if (jahistoria!=0){
			cout<<"Você já escolheu história";
			goto tirdchoice;
		}
		jahistoria++;
		skills.insert("história");
	}

	if(opskill==5){
		if (jainsight!=0){
			cout<<"Você já escolheu artes marciais";
			goto tirdchoice;
		}
		jainsight++;
		skills.insert("artes marciais");
	}

	if(opskill==6){
		if (jaintimidacao!=0){
			cout<<"Você já escolheu intimidação";
			goto tirdchoice;
		}
		jaintimidacao++;
		skills.insert("intimidação");
	}

	if(opskill==7){
		if (jainvestigacao!=0){
			cout<<"Você já escolheu investigação";
			goto tirdchoice;
		}
		jainvestigacao++;
		skills.insert("investigação");
	}

	if(opskill==8){
		if (jamedicina!=0){
			cout<<"Você já escolheu medicina";
			goto tirdchoice;
		}
		jamedicina++;
		skills.insert("medicina");
	}

	if(opskill==9){
		if (jatecnologia!=0){
			cout<<"Você já escolheu tecnologia";
			goto tirdchoice;
		}
		jatecnologia++;
		skills.insert("tecnologia");
	}

	if(opskill==10){
		if (japercepcao!=0){
			cout<<"Você já escolheu percepção";
			goto tirdchoice;
		}
		japercepcao++;
		skills.insert("percepção");
	}

	if(opskill==11){
		if (japerformance!=0){
			cout<<"Você já escolheu performance";
			goto tirdchoice;
		}
		japerformance++;
		skills.insert("performance");
	}

	if(opskill==12){
		if (japersuasao!=0){
			cout<<"Você já escolheu persuasão";
			goto tirdchoice;
		}
		japersuasao++;
		skills.insert("persuasão");
	}

	if(opskill==13){
		if (jadesculpas!=0){
			cout<<"Você já escolheu desculpas rápidas";
			goto tirdchoice;
		}
		jadesculpas++;
		skills.insert("desculpas rápidas");
	}

	if(opskill==14){
		if (jamimetagem!=0){
			cout<<"Você já escolheu mimetagem";
			goto tirdchoice;
		}
		jamimetagem++;
		skills.insert("mimetagem");
	}

	if(opskill==15){
		if (jastealth!=0){
			cout<<"Você já escolheu stealth";
			goto tirdchoice;
		}
		jastealth++;
		skills.insert("stealth");
	}

	if(opskill==16){
		if (jasobrevivencia!=0){
			cout<<"Você já escolheu sobrevivência";
			goto tirdchoice;
		}
		jasobrevivencia++;
		skills.insert("sobrevivência");
	}

	system("cls");
	cout<<"Você já é proficiente em: ";

	for(set<string>::iterator it=skills.begin(); it!=skills.end(); it++){
		cout<<*it<<", ";
	}


	cout<<"\n\n\n";
	system("pause");
	system("cls");

	/*-------------------------Compras e equipamentos-----------------------------*/

/*Armas, armaduras e equipamentos funcionam como vetores, as informações armazenadas neles são
manipuladas e ordenas usando métodos padrão. A escolha pela estrutura aqui deve-se
pela necessidade de armazenar mais uma "coisa" numa mesmas categoria.

O extenso código abaixo cobre as operações de compra.*/


	cout<<"Agora vamos as compras.\nVocê tem "<<mangos<<" para gastar em armadura, armas e equipamentos básicos.\n\n";
	cout<<"Você quer ver a o catálogo do que você pode comprar para fazer escolhas conscientes ?\n(0) Não (1) Sim\nResposta: ";

	int listaequip;
	cin>>listaequip;
//Abre a lista de equipamentos no navegador
	if (listaequip==1)
		system("start https://drive.google.com/file/d/16TbgPx8fwzL0Ur-GRfX9qlISlvs0C3kK/view");

	cout<<"\n\n";
	system("pause");
	system("cls");

	int numarmadura;

	if(numclasse==3){
		cout<<"O equipamentos especial de sua classe é uma armadura kevlar discreta de armor class 16\nPor isso você não precisa comprar uma armadura";
		armorclass=16;
		armadura="Kevlar discreta";
	}

	else{
		cout<<"Primeiro vamos escolher sua armadura\nAC=Armor Class\n\n";
		cout<<"(0) Nenhuma\n\nLeve: Discreta, por debaixo da roupa\n\n(1) Camisa reforçada AC:11 Preço:100\n(2) Colete interno AC:12 Preço:200\n\nMédia: Discreta, por debaixo da roupa, resistente a penetração de arma branca\n\n(3) Camisa a prova de bala AC:13 Preço:500\n(4) Camisa a prova de bala reforçada AC:14 Preço: 750\n\nPesada: Por cima da roupa, resistente a penetração de arma branca\n\n(5) Kevlar AC:16 Preço:1000\n\n\n";

		escolherarmadura:
		cout<<"Número da armadura: ";
		cin>>numarmadura;

		if (numarmadura==0){
			armorclass=0;
			armadura="nenhuma armadura";
			}

		else if (numarmadura==1){
			armorclass=11;
			armadura="Camisa reforçada";
			mangos=mangos-100;
			}

		else if (numarmadura==2){
			armorclass=12;
			armadura="Colete interno";
			mangos=mangos-200;
			}

		else if (numarmadura==3){
			armorclass=13;
			armadura="Camisa a prova de bala";
			mangos=mangos-500;
			}

		else if (numarmadura==4){
			armorclass=14;
			armadura="Camisa a prova de bala reforçada";
			mangos=mangos-750;
			}

		else if (numarmadura==5){
			armorclass=16;
			armadura="Kevlar";
			mangos=mangos-1000;
			}

		if ((numarmadura==0) || (numarmadura==1) || (numarmadura==2) || (numarmadura==3) || (numarmadura==4) || (numarmadura==5))
    		cout<<"";

		else{
			cout<<"Número digitado não corresponde a nenhuma armadura";
    		goto escolherarmadura;
			}
	}

	cout<<"\n\n\n";
	system("cls");

	int xarma;
	vector<int>volTA;

	cout<<"Agora vamos escolher suas armas";

	escolhasarmas:
	int numarma;
	xarma=volTA.size()-1;

	cout<<"\nDinheiro restante: "<<mangos;
	cout<<"\n(0) Já comprei todas as armas que eu queria\n(99) Voltar uma ação\n\nCorpo a corpo simples\n\n(1) Canivete suíço Dano:1d4 Preço:75\n(2) Faca Dano:1d4 Preço:150\n(3) Taco retrátil Dano:1d4 Preço:150\n\nCorpo a corpo tradicional\n\n(4) Shuriken Dano:1d4 Preço:30\n(5) Nunchaku Dano:1d4 Preço:150\n(6) Chicote Dano:1d4 Preço:150\n(7) Adaga Dano:1d4 Dano:150\n(8) Bengala-espada Dano:1d8 Preço:300\n(9) Katana Dano:1d10 Preço:300\n\nArmas simples\n\n(10) Cachimbo pistola Dano:1d6 Preço:150\n(11) Pistola Dano:1d8 Preço:300\n(12) Pistola alto calibre Dano:1d10 Preço:350\n\nArmas militares\n\n(13) Sniper rifle Dano:2d6 Preço:500\n";

	escolherarma:
	cout<<"\nNúmero da arma: ";
	cin>>numarma;

	if (numarma==99){
		xarma=volTA.size()-1;
		if (volTA[xarma]==1){mangos=mangos+75;}
		if (volTA[xarma]==2){mangos=mangos+150;}
		if (volTA[xarma]==3){mangos=mangos+150;}
		if (volTA[xarma]==4){mangos=mangos+30;}
		if (volTA[xarma]==5){mangos=mangos+150;}
		if (volTA[xarma]==6){mangos=mangos+15;}
		if (volTA[xarma]==7){mangos=mangos+150;}
		if (volTA[xarma]==8){mangos=mangos+300;}
		if (volTA[xarma]==9){mangos=mangos+300;}
		if (volTA[xarma]==10){mangos=mangos+150;}
		if (volTA[xarma]==11){mangos=mangos+300;}
		if (volTA[xarma]==12){mangos=mangos+350;}
		if (volTA[xarma]==13){mangos=mangos+500;}
		volTA.erase (volTA.end()-1);
		armas.pop_back();

		system("cls");
// mostra quantas armas vc tem 
    	cout<<"Você já comprou: ";
			while(!armas.empty()){
		    cout<<armas.front()<<", ";
		    vazia.push_back(armas.front());
		    armas.pop_front();
		  }
		  swap(vazia, armas);
    	goto escolhasarmas;
	}

	if (numarma==0)
	cout<<" ";

	else{
		if (numarma==1){
			if(mangos < 75) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Canivete suíço(1d4)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

    		mangos=mangos-75;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==2){
			if(mangos < 150) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Faca(1d4)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

    		mangos=mangos-150;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==3){
			if(mangos < 150) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Taco retrátil(1d4)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

    		mangos=mangos-150;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==4){
			if(mangos < 30) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Shuriken(1d4)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

    		mangos=mangos-30;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==5){
			if(mangos < 150) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Nunchako(1d4)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

    		mangos=mangos-150;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==6){
			if(mangos < 150) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Chicote(1d4)");
   			system("cls");
   			cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

    		mangos=mangos-150;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==7){
			if(mangos < 150) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

	    	armas.push_back("Adaga(1d4)");
	    	system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

    		mangos=mangos-150;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==8){
			if(mangos < 300) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Bengala espada(1d8)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-300;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==9){
			if(mangos < 300) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Katana(1d10)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-300;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==10){
			if(mangos < 150) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Cachimbo pistola(1d6)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-150;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==11){
			if(mangos < 300) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Pistola(1d8)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

    		mangos=mangos-300;
    		volTA.push_back(numarma);
			goto escolhasarmas;
		}

		if (numarma==12){
			if(mangos < 350) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Pistola alto calibre(1d10)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-350;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if (numarma==13){
			if(mangos < 500) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasarmas;
			}

    		armas.push_back("Sniper rifle(2d6)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-500;
    		volTA.push_back(numarma);
    		goto escolhasarmas;
		}

		if ((numarma==0) || (numarma==99) || (numarma==1) || (numarma==2) || (numarma==3) || (numarma==4) || (numarma==5) || (numarma==6) || (numarma==7) || (numarma==8) || (numarma==9) || (numarma==10) || (numarma==11) || (numarma==12) || (numarma==13))
    		cout<<"";

		else{
			cout<<"Número digitado não corresponde a nenhuma arma";
    		goto escolherarma;
		}
	}


	system("cls");

	int xexplo;
	vector<int>voltA;
	xexplo=voltA.size()-1;

	cout<<"Agora os explosivos";

	escolhasexplo:
	int numexplo;

	cout<<"\n\nDinheiro restante: "<<mangos;
	cout<<"\n\n(0) Já comprei todos os explosivos que eu queria\n(99) Voltar uma ação\n\nExplosivos\n\n(1) Bomba de fumaça (desnorteia por 1 rodada)Preço:20 \n(2) Bomba de Luz (cega por uma rodada)Preço:20 \n(3) Bomba sonífera (faz desmaiar por 8 horas)Preço:20 \n(4) Isqueiro granada (2d6)Preço:30 \n(5) Chiclete explosivo (2d6)Preço:30 \n(6) Flor de lapela explosiva (2d6)Preço:30 \n(7) Granada adesiva (3d6)Preço:50 \n(8) Granada (3d6)Preço:50 ";

	escolherexplo:

	cout<<"\n\n\nNúmero do explosivo: ";
	cin>>numexplo;

	if (numexplo==99){
		xexplo=voltA.size()-1;
		if (voltA[xexplo]==1){mangos=mangos+20;}
		if (voltA[xexplo]==2){mangos=mangos+20;}
		if (voltA[xexplo]==3){mangos=mangos+20;}
		if (voltA[xexplo]==4){mangos=mangos+30;}
		if (voltA[xexplo]==5){mangos=mangos+30;}
		if (voltA[xexplo]==6){mangos=mangos+30;}
		if (voltA[xexplo]==7){mangos=mangos+50;}
		if (voltA[xexplo]==8){mangos=mangos+50;}
		voltA.erase (voltA.end()-1);
		armas.pop_back();

		system("cls");
    	cout<<"Você já comprou: ";

			while(!armas.empty()){
		    cout<<armas.front()<<", ";
		    vazia.push_back(armas.front());
		    armas.pop_front();
		  }
		  swap(vazia, armas);

    	goto escolhasexplo;
	}

	if (numexplo==0)
		cout<<" ";

	else{
		if (numexplo==1){
			if(mangos < 20) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasexplo;
			}

		    armas.push_back("Bomba de fumaça");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-20;
    		voltA.push_back(numexplo);
    		goto escolhasexplo;
		}

		else if (numexplo==2){
			if(mangos < 20) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasexplo;
			}

   			armas.push_back("Bomba de luz");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-20;
    		voltA.push_back(numexplo);
    		goto escolhasexplo;
		}

		else if (numexplo==3){
			if(mangos < 20) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasexplo;
			}

    		armas.push_back("Bomba sonífera");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-20;
    		voltA.push_back(numexplo);
    		goto escolhasexplo;
		}

		else if (numexplo==4){
			if(mangos < 30) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasexplo;
			}

    		armas.push_back("Isqueiro granada(2d6)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-30;
    		voltA.push_back(numexplo);
    		goto escolhasexplo;
			}

		else if (numexplo==5){
			if(mangos < 30) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasexplo;
			}

    		armas.push_back("Chiclete explosivo(2d6)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-30;
    		voltA.push_back(numexplo);
    		goto escolhasexplo;
		}

		else if (numexplo==6){
			if(mangos < 30) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasexplo;
			}

    		armas.push_back("Flor de lapela explosiva(2d6)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-30;
    		voltA.push_back(numexplo);
    		goto escolhasexplo;
		}

		else if (numexplo==7){
			if(mangos < 50) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasexplo;
			}

    		armas.push_back("Granada adesiva(3d6)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-50;
 			voltA.push_back(numexplo);
    		goto escolhasexplo;
		}

		else if (numexplo==8){
			if(mangos < 50) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasexplo;
			}

    		armas.push_back("Granada(3d6)");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!armas.empty()){
			    cout<<armas.front()<<", ";
			    vazia.push_back(armas.front());
			    armas.pop_front();
			  }
			  swap(vazia, armas);

			mangos=mangos-50;
    		voltA.push_back(numexplo);
    		goto escolhasexplo;
		}

		if ((numexplo==0) || (numexplo==99) || (numexplo==1) || (numexplo==2) || (numexplo==3) || (numexplo==4) || (numexplo==5) || (numexplo==6) || (numexplo==7) || (numexplo==8))
    		cout<<"";

		else{
			cout<<"Número digitado não corresponde a nenhum explosivo";
    		goto escolherexplo;
		}
	}


	system("cls");

	int xequip;
	vector<int>volta;

	cout<<"Agora vamos escolher seus equipamentos";

	escolhasequip:

	int numequip;
	xequip=volta.size()-1;


	cout<<"\nDinheiro restante: "<<mangos;
	cout<<"\n\n(0) Já comprei todos os equipamentos que eu queria\n(99) Voltar uma ação\n\n(1) Grampo de lockpick Preço:1 \n(2) Saco de dormir Preço:5 \n(3) Primeiros-socorros Preço:10 \n(4) Lanterna Preço:10 \n(5) Sapato-fone Preço:20 \n(6) Munição sonífera Preço:25 \n(7) Rastreador magnético Preço:50 \n(8) Silenciador Preço:50 \n(9) Respirador Preço:75 \n(10) Bússola Preço:100 \n(11) Gravador de voz Preço:100 \n(12) Relógio inteligente Preço:150 \n(13) Binóculos com visão noturna Preço:150 \n(14) Arpéu Preço:200 \n(15) Gravata câmera Preço:200 \n(16) Anel câmera Preço:200 \n(17) Óculos especiais Preço:300 \n(18) Máscara de gás Preço:500 \n(19) Caneta eletro-ímã Preço:500 \n(20) Carimbo adaptativo Preço:500 \n(21) Falsificador de assinaturas Preço:500\n ";

	escolherequip:
	cout<<"\nNúmero do equipamentos: ";
	cin>>numequip;

	if (numequip==99){
		xequip=volta.size()-1;
		if (volta[xequip]==1){mangos=mangos+1;}
		if (volta[xequip]==2){mangos=mangos+5;}
		if (volta[xequip]==3){mangos=mangos+10;}
		if (volta[xequip]==4){mangos=mangos+10;}
		if (volta[xequip]==5){mangos=mangos+20;}
		if (volta[xequip]==6){mangos=mangos+25;}
		if (volta[xequip]==7){mangos=mangos+50;}
		if (volta[xequip]==8){mangos=mangos+50;}
		if (volta[xequip]==9){mangos=mangos+75;}
		if (volta[xequip]==10){mangos=mangos+100;}
		if (volta[xequip]==11){mangos=mangos+100;}
		if (volta[xequip]==12){mangos=mangos+150;}
		if (volta[xequip]==13){mangos=mangos+150;}
		if (volta[xequip]==14){mangos=mangos+200;}
		if (volta[xequip]==15){mangos=mangos+200;}
		if (volta[xequip]==16){mangos=mangos+200;}
		if (volta[xequip]==17){mangos=mangos+300;}
		if (volta[xequip]==18){mangos=mangos+500;}
		if (volta[xequip]==19){mangos=mangos+500;}
		if (volta[xequip]==20){mangos=mangos+500;}
		if (volta[xequip]==21){mangos=mangos+500;}
		volta.erase (volta.end()-1);
		equipamentos.pop_back();
		system("cls");

    	cout<<"Você já comprou: ";

		while(!equipamentos.empty()){
		   cout<<equipamentos.front()<<", ";
		   vazia.push_back(equipamentos.front());
		   equipamentos.pop_front();
		}
		swap(vazia, equipamentos);

		goto escolhasequip;
	}

	if (numequip==0)
		cout<<" ";

	else{
		if (numequip==1){
			if(mangos < 1) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Grampo de lockpick");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-1;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==2){
			if(mangos < 5) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Saco de dormir");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-5;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==3){
			if(mangos < 10) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Primeiros socorros");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-10;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==4){
			if(mangos < 10) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Lanterna");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-10;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==5){
			if(mangos < 20) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Sapato-fone");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-20;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==6){
			if(mangos < 25) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Munição sonífera");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-25;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==7){
			if(mangos < 50) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Rastreador magnético");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-50;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==8){
			if(mangos < 50) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Silenciador");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-50;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==9){
			if(mangos < 75) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Respirador");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-75;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==10){
			if(mangos < 150) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Bússola");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-150;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==11){
			if(mangos < 100) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Gravador de voz");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-100;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==12){
			if(mangos < 100) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Relógio inteligente");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-100;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==13){
			if(mangos < 150) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Binóculos com visão noturna");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-150;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==14){
			if(mangos < 200) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Arpéu");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-200;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==15){
			if(mangos < 200) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Gravata câmera");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-200;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==16){
			if(mangos < 200) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Anel câmera");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-200;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==17){
			if(mangos < 300) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Óculos especiais");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-300;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==18){
			if(mangos < 500) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Máscara de gás");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-500;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==19){
			if(mangos < 500) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Caneta eletro-ímã");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-500;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==20){
			if(mangos < 500) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Carimbo adaptativo");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-500;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		else if (numequip==21){
			if(mangos < 500) {
				cout << "\nDinheiro insuficiente." << endl;
				system ("pause");
				system("cls");
				goto escolhasequip;
			}

    		equipamentos.push_back("Falsificador de assinaturas");
    		system("cls");
    		cout<<"Você já comprou: ";

				while(!equipamentos.empty()){
				   cout<<equipamentos.front()<<", ";
				   vazia.push_back(equipamentos.front());
				   equipamentos.pop_front();
				}
				swap(vazia, equipamentos);

			mangos=mangos-500;
    		volta.push_back(numequip);
    		goto escolhasequip;
		}

		if ((numequip==0) || (numequip==99) || (numequip==1) || (numequip==2) || (numequip==3) || (numequip==4) || (numequip==5) || (numequip==6) || (numequip==7) || (numequip==8) || (numequip==9) || (numequip==10) || (numequip==11) || (numequip==12) || (numequip==13)|| (numequip==13)|| (numequip==14)|| (numequip==15)|| (numequip==16)|| (numequip==17)|| (numequip==18)|| (numequip==19)|| (numequip==20)|| (numequip==21))
    		cout<<"";

		else{
			cout<<"Número digitado não corresponde a nenhum equipamentos";
    		goto escolherequip;}
	}
	
	//-------------------------Observação Especial-------------------------------
	/* Antes de salvar o personagem que foi criado, vamos salvar uma obeservação
	especial sobre ele, como algo para ajudar o usuário a lembrar porque criou
	o personagem com certos atributos e equipamentos */
	
	cout << "\n";
	system("pause");
	system("cls");
	
	cout << "\n Escreva uma observação sobre o personagem para ser salva no arquivo e te ajudar futuramente,\n a lembrar porquê criou tal personagem." << endl;
	string obs = "";
	getline(cin, obs);
	getline(cin, obs);

	//-------------------------Perfil do Personagem-------------------------------
	/*Agora, com todas as informações devidamente coletadas, nós instanciamos um
	objeto personagem e depois chamamos o método resumo para mostrar todas as informações
	e fazemos uma ficha do personagem em um arquivo .txt*/
	
	system("cls");
	
	Personagem agente(armadura,armorclass,classe,sexo,name,si,mangos,equipamentos,hitpoints,habilidades,armas,acao,saving,skills,forca,dest,Const,inte,sabedoria,carisma,mforca,mdest,mConst,minte,msabedoria,mcarisma);
	agente.resumo();
	system("pause");
	struct tm *dataagora;
	time_t segundos;
	time(&segundos);
	dataagora=localtime(&segundos);

	ofstream ficha;
	ficha.open("fichaD&D5espião.txt", ios::app);
	ficha<<"\n"<<dataagora->tm_mday<<"/"<<dataagora->tm_mon+1<<"/"<<dataagora->tm_year+1900<<"\n";
	ficha<<dataagora->tm_hour<<":"<<dataagora->tm_min<<":"<<dataagora->tm_sec<<"\n";
	ficha<<"Observação: "<<obs<<"\n\n";
	ficha<<"Nome do agente: "<<name<<"\nIdentidade secreta: "<<si<<endl;
	ficha<<"Classe: "<<classe<<endl;
	ficha<<"Hit-points: "<<hitpoints<<endl;
	ficha<<"Armor class: "<<armorclass<<" ("<<armadura<<")\n";
	ficha<<"Dinheiro local: "<<mangos<<"\n";
	ficha<<"Habilidade especial: "<<habilidades<<endl;

	ficha<<"Armas de seu arsenal: ";
	while(!armas.empty()){
		ficha<<armas.front()<<", ";
		vazia.push_back(armas.front());
		armas.pop_front();
	}
	swap(vazia, armas);
	ficha<<endl;

	ficha<<"Equipamentos: ";
	while(!equipamentos.empty()){
		 ficha<<equipamentos.front()<<", ";
		 vazia.push_back(equipamentos.front());
		 equipamentos.pop_front();
	}
	swap(vazia, equipamentos);
	ficha<<endl;

	ficha<<"Proficiência em saving throw: "<<saving<<endl;

	ficha<<"Bônus de proficiência: 2\n";
	ficha<<"Iniciativa: "<<mdest<<endl;
	ficha<<"Deslocamento: 10 metros\n";

	ficha<<"Skills: ";
	for(set<string>::iterator it=skills.begin(); it!=skills.end(); it++){
		ficha<<*it<<", ";
	}

	ficha<<endl;

	ficha<<"Atributos e seus modificadores-\nForça: "<<forca<<" ("<<mforca<<")\nDestreza: "<<dest<<" ("<<mdest<<")\nConstituição: "<<Const<<" ("<<mConst<<")\nInteligência: "<<inte<<" ("<<minte<<")\nSabedoria: "<<sabedoria<<" ("<<msabedoria<<")\nCarisma: "<<carisma<<" ("<<mcarisma<<")";
	ficha<<"\n\nBoa jogatina agente\n";
	ficha.close();

	return 0;
}



