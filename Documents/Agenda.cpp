#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>
#include <cstring>

//ESTRUTURA DE DATA ANIVERSARIO
struct data
{
    int dia,mes,ano;
};

//ESTRUTURA DOS DADOS DA AGENDA
struct dados
{
    std::string nome,celular,email;
    std::string mensagemAniversario;
    data dataAniversario;
    //STATUS:
    //0 - Nao Cadastrado ;  1 - Cadastrado ; 2 - Alterado ; 3 - Deletado
    int status;  
};


class Dados
{
    //ATRIBUTOS DA CLASSE
    private: dados dd;   
    
    //CRIAR METODO CONSTRUTOR
    public: Dados()
    {
        data nv;
        
        nv.dia=0;
        nv.mes=0;
        nv.ano=0;
        
        dd.nome="";
        dd.celular="";
        dd.email="";
        dd.dataAniversario=nv;
        dd.mensagemAniversario="ERRO - NAO CADASTRADO";
        dd.status=0;        
    };
    
    public: int Inicializar()
    {
        data nv;
        
        nv.dia=0;
        nv.mes=0;
        nv.ano=0;
        
        dd.nome="";
        dd.celular="";
        dd.email="";
        dd.dataAniversario=nv;
        dd.mensagemAniversario="ERRO - NAO CADASTRADO";
        dd.status=0;
        
        return dd.status;
    }
    
    //CADASTRAR OS VALORS NO ATRIBUTO dd
    //INPUT
    //std::string nome,celular,email;
    // data dataAniversario;
    //
    //OUTPUT
    //STATUS:
    //0 - Nao Cadastrado ;  1 - Cadastrado ; 2 - Alterado ; 3 - Deletado
    public: int Cadastrar(std::string nm,std::string cel,std::string eml, data niver)
    {
        dd.nome=nm;
        dd.celular=cel;
        dd.email=eml;
        dd.dataAniversario=niver;
        dd.mensagemAniversario="";
        dd.status=1;
        
        return dd.status;
    };
    
    //DELETAR
    public: int Deletar()
    {
        data nv;
        
        nv.dia=0;
        nv.mes=0;
        nv.ano=0;
        
        //dd.nome="";
        //dd.celular="";
        //dd.email="";
        //dd.dataAniversario=nv;
        //dd.mensagemAniversario="REGISTRO DELETADO";
        dd.status=3;  
        
        return dd.status;
    }

    //ALTERA POR nome
    public: int AlterarNome(std::string nm)
    {
        dd.nome = nm;
        dd.status=2;  
        
        return dd.status;
    }

    //ALTERAR POR CELULAR
    public: int AlterarCelular(std::string cel)
    {
        dd.celular = cel;
        dd.status=2;  
        
        return dd.status;
    }

    //ALTERAR POR EMAIL
    public: int AlterarEmail(std::string eml)
    {
        dd.email = eml;
        dd.status=2;  
        
        return dd.status;
    }
    
    //CONSULTAR POR nome
    public: int ConsultarNome(std::string nm)
    {
        if(dd.nome==nm)
        {
            return dd.status;
        }
        else
            return 0;
    }

    //CONSULTAR POR Celular
    public: int ConsultarCelular(std::string cel)
    {
        if(dd.celular==cel)
        {
            return dd.status;
        }
        else
            return 0;
    }    

    //CONSULTAR POR Email
    public: int ConsultarEmail(std::string eml)
    {
        if(dd.email==eml)
        {
            return dd.status;
        }
        else
            return 0;
    }    
        
    public: std::string ValidadeAniversario(data nv)
    {
        if ( (dd.dataAniversario.dia==nv.dia)&&(dd.dataAniversario.mes==nv.mes)&&
              (dd.dataAniversario.ano==nv.ano) )
          dd.mensagemAniversario="PARABENS HOJE EH O DIA DO SEU ANIVERSARIO";
        else
          dd.mensagemAniversario="QUE PENA AINDA NAO EH O SEU ANIVERSARIO";
              
        return dd.mensagemAniversario;
    }
    
    public: std::string getMensagemAniversario()
    {
        return dd.mensagemAniversario;
    }
    
    //getNOME RETORNAR O nome
    public: std::string getNome()
    {
        return dd.nome;
    };
    
    //getNOME RETORNAR O celular
    public: std::string getCelular()
    {
        return dd.celular;
    };
    
    //getNOME RETORNAR O email
    public: std::string getEmail()
    {
        return dd.email;
    };
    
    //getNOME RETORNAR A DATA DE NARCIMENTO
    public: data getDataNascimento()
    {
        return dd.dataAniversario;
    };
    
    //getStatus RETORNAR O status
    public: int getStatus()
    {
        return dd.status;
    }
    
    //getMsgStatus RETORNAR O status
    public: std::string getMsgStatus()
    {
        if(dd.status==0)
            return "REGISTRO NAO CADASTRADO";
        if(dd.status==1)
            return "REGISTRO CADASTRADO";
        if(dd.status==2)
            return "REGISTRO CADASTRADO E ALTERADO"; 
        if(dd.status==3)
            return "REGISTRO DELETADO";
            
        return "ERRO";
    }
};


//CLASSE AGENDA CONTENDO VARIOS  CADASTROS
class AGENDA
{
    //ATRIBUTOS
    private: int maxCadastros=1000;
    private: Dados dd[1000];   
    private: int nCadastros;
    
    public: AGENDA()
    {
        nCadastros=0;
        for(int i=0;i<maxCadastros;i++)
        {
            dd[i].Inicializar();
        }
    };
    
    public: int Inicializar()
    {
        nCadastros=0;
        for(int i=0;i<maxCadastros;i++)
        {
            dd[i].Inicializar();
        }
        
        return maxCadastros;
    };
    
    //METODO Cadastrar
    //INPUT:
    //nome, celular, email, data aniversario
    //OUTPUT:
    //status
    public: int Cadastrar(std::string nm,std::string cel,std::string eml, data niver)
    {
        int status;
        
        dd[nCadastros].Cadastrar(nm,cel,eml,niver);
        status=dd[nCadastros].getStatus();
        
        nCadastros++;
        return status; 
    };
    
    //CONSULTAR POR NOME
    //INPUT:
    //nome
    //OUTPUT:
    //status
    public: int ConsultarNome(std::string nm)
    {
        int status=0;
        int aux;
        
        for ( int i =0 ; i<nCadastros;i++)
        {
            aux=dd[i].ConsultarNome(nm);
            
            if((aux==1)||(aux==2))
                status=aux;
        }
        
        return status;
    };
    
    //CONSULTAR POR CELULAR
    //INPUT:
    //nome
    //OUTPUT:
    //status
    public: int ConsultarCelular(std::string cel)
    {
        int status=0;
        int aux;
        
        for ( int i = 0 ; i<nCadastros;i++)
        {
            aux=dd[i].ConsultarCelular(cel);
            
            if((aux==1)||(aux==2))
                status=aux;
        }
        
        return status;
    };
    
    //METODO PARA RETORNAR O NUMERO DE CADASTRO NA AGENDA
    public: int getNumeroCadastros()
    {
        return nCadastros;
    }
    
    //RETORNA O NOME DE UM REGISTRO ESPECIFICO:  pos
    public: std::string getNome(int pos)
    {
        int status= dd[pos].getStatus();
        if ((status==1)||(status==2))
            return dd[pos].getNome();
        else
           return "DELETADO";
    }
    
    //RETORNA O CELULAR DE UM REGISTRO ESPECIFICO:  pos
    public: std::string getCelular(int pos)
    {
        int status= dd[pos].getStatus();
        if ((status==1)||(status==2))
            return dd[pos].getCelular();
        else
           return "DELETADO";
    }
    
    //RETORNA O EMAIL DE UM REGISTRO ESPECIFICO:  pos
    public: std::string getEmail(int pos)
    {
        int status= dd[pos].getStatus();
        if ((status==1)||(status==2))
            return dd[pos].getEmail();
        else
           return "DELETADO";
    }
    
    //RETORNA O NOME DE UM REGISTRO ESPECIFICO:  pos
    public: data getDataNascimento(int pos)
    {
        data nv;
        nv.dia=0;
        nv.mes=0;
        nv.ano=0;
        int status= dd[pos].getStatus();
        if ((status==1)||(status==2))
            return  dd[pos].getDataNascimento();
        else
           return nv;
        
    }
    
    //CONSULTAR EMAIL
    public: int ConsultarEmail(std::string eml)
    {
        int status=0;
        int aux;
        
        for ( int i =0 ; i<nCadastros;i++)
        {
            aux = dd[i].ConsultarEmail(eml);
            
            if((aux==1)||(aux==2))
                status=aux;
        }
        
        return status;
    };
    
    //DELETAR nome
    public: int DeletarNome(std::string nm)
    {
        int auxStatus;
        int status=0;
        
        //PERCORRER A BASE DE DADOS
        //PROCURENDO O REGISTRO COM O NOME nm
        for(int i=0; i<nCadastros;i++)
        {
            auxStatus=dd[i].ConsultarNome(nm);
            if ((auxStatus==1)||(auxStatus==2))
                {
                  dd[i].Deletar();
                  return 3;
                }
            if(auxStatus==3)
               return 3;
        }
        
        return status;
    };
    
    //DELETAR CELULAR
    public: int DeletarCelular(std::string cel)
    {
        int auxStatus;
        int status=0;
        
        //PERCORRER A BASE DE DADOS
        //PROCURENDO O REGISTRO COM O NOME nm
        for(int i=0; i<nCadastros;i++)
        {
            auxStatus=dd[i].ConsultarCelular(cel);
            if ((auxStatus==1)||(auxStatus==2))
                {
                  dd[i].Deletar();
                  return 3;
                }
            if(auxStatus==3)
               return 3;
        }
        return 0;
    };
    
    //ALTERAR NOME
    public: int AlterarNome(std::string nm, std::string nm2)
    {
        int auxStatus;
        int status=0;
        
        //PERCORRER A BASE DE DADOS
        //PROCURENDO O REGISTRO COM O NOME nm
        for(int i=0; i<nCadastros;i++)
        {
            auxStatus=dd[i].ConsultarNome(nm);
            if ((auxStatus==1)||(auxStatus==2))
                {
                  dd[i].AlterarNome(nm2);
                  return 2;
                }
            if(auxStatus==3)
               return 3;
        }
        return 0;
    };
    
    //ALTERAR CELULAR
    public: int AlterarCelular(std::string cel, std::string cel2)
    {
        int auxStatus;
        int status=0;
        
        //PERCORRER A BASE DE DADOS
        //PROCURENDO O REGISTRO COM O CELULAR
        for(int i=0; i<nCadastros;i++)
        {
            auxStatus=dd[i].ConsultarCelular(cel);
            if ((auxStatus==1)||(auxStatus==2))
                {
                  dd[i].AlterarCelular(cel2);
                  return 2;
                }
            if(auxStatus==3)
               return 3;
        }
        return 0;
    };

    //ALTERAR EMAIL
    public: int AlterarEmail(std::string eml, std::string eml2)
    {
        int auxStatus;
        int status=0;
        
        //PERCORRER A BASE DE DADOS
        //PROCURENDO O REGISTRO COM O EMAIL
        for(int i=0; i<nCadastros;i++)
        {
            auxStatus=dd[i].ConsultarEmail(eml);
            if ((auxStatus==1)||(auxStatus==2))
                {
                  dd[i].AlterarEmail(eml2);
                  return 2;
                }
            if(auxStatus==3)
               return 3;
        }
        return 0;
    };
};


int main()
{
    //DEFINIR AGENDA
    AGENDA ag;
    int cadastrosAgenda=0;
    
    std::string nome,celular,email;
    std::string mensagemAniversario;
    data dataAniversario;
    int status;
    
    
    //INICIALIZAR AGENDA
    ag.Inicializar();
    
    data nv;
        
    nv.dia=30;
    nv.mes=2;
    nv.ano=2000;
    status=ag.Cadastrar("PERCIVAL","999123456","percy@gmail.com",nv);
    
    nv.dia=16;
    nv.mes=11;
    nv.ano=2005;
    status=ag.Cadastrar("GUYLYERMY","912345678","guylyermy@gmail.com",nv);
    
    nv.dia=7;
    nv.mes=12;
    nv.ano=1941;
    status=ag.Cadastrar("QAUAN","9999999999","quauan@gmail.com",nv);
    
    nv.dia=8;
    nv.mes=9;
    nv.ano=1970;
    status=ag.Cadastrar("BEETHOR","888654321","beethor@gmail.com",nv);

    //NUMERO DE REGISTROS EFETUADOS NA AGENDA
    cadastrosAgenda=ag.getNumeroCadastros();
    for(int i = 0 ; i<cadastrosAgenda ; i++)
    {
        std::cout<<"\n\n"<<i<<"\t"<<ag.getNome(i);
        std::cout<<"\n\t"<<ag.getCelular(i);
        std::cout<<"\n\t"<<ag.getEmail(i);
        nv=ag.getDataNascimento(i);
        std::cout<<"\n\tDATA NASCIMENTO: "<<nv.dia<<"/"<<nv.mes<<"/"<<nv.ano;
    }
    
    
    //DELETAR
    status=ag.DeletarNome("GUYLYERMY");
    if(status==3)
       std::cout<<"\n\nREGISTRO FOI DELETADO";

    //DELETAR
    status=ag.DeletarCelular("888654321");
    if(status==3)
    std::cout<<"\n\nREGISTRO FOI DELETADO";

    //ALTERAR
    status=ag.AlterarNome("PERCIVAL", "MATHEUS OLIVEIRA");
    if(status==2)
    std::cout<<"\n\nNOME ALTERADO";
    if(status==3)
    std::cout<<"\n\nREGISTRO FOI DELETADO";

    //ALTERAR
    status=ag.AlterarEmail("percy@gmail.com", "matheus@gmail.com");
    if(status==2)
    std::cout<<"\n\nEMAIL ALTERADO";
    if(status==3)
    std::cout<<"\n\nREGISTRO FOI DELETADO";

    //ALTERAR
    status=ag.AlterarCelular("9999999999", "1111111111");
    if(status==2)
    std::cout<<"\n\nCELULAR ALTERADO";
    if(status==3)
    std::cout<<"\n\nREGISTRO FOI DELETADO";
    

    //NUMERO DE REGISTROS EFETUADOS NA AGENDA
    cadastrosAgenda=ag.getNumeroCadastros();
    for(int i = 0 ; i<cadastrosAgenda ; i++)
    {
        std::cout<<"\n\n"<<i<<"\t"<<ag.getNome(i);
        std::cout<<"\n\t"<<ag.getCelular(i);
        std::cout<<"\n\t"<<ag.getEmail(i);
        nv=ag.getDataNascimento(i);
        std::cout<<"\n\tDATA NASCIMENTO: "<<nv.dia<<"/"<<nv.mes<<"/"<<nv.ano;
    }
    
    return 0;
}

