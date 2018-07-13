/*
            ################################################
            #                                              # 
            # BIBLIOTECA DE MANIPULAÇÂO COM BANCO DE DADOS #
            #                                              #
            # desenvolvida por: THIAGO MARAN GARCIA        #
            # e-mail: thiagomaran@gmail.com                # 
            # data:30/04/2013                              #
            ################################################

*/
#include <winsock2.h>     
#include <mysql/mysql.h>

char * host = "localhost";     // Pode ser o nome do computador ou o IP
   
char * usuario = "root";      // Usuário para conectar (troque pelo seu usuário)
   
char * senha = "root";   // Senha do usuário (troque pelo senha do seu usuário)
   
char * database = "nibiru";   // Base de dados a se conectar (troque pelo seu database)


/*
#################################################
#        Inicio  Consulta Unica                 # 
#################################################
*/
char * ConsultaUnica(char sql[254]){   
  
   MYSQL * conexao;               // Cria um link para a conexão
   conexao = mysql_init(NULL);    // Inicializa o link
   // Conectando ao banco!
   if (!mysql_real_connect(conexao, host, usuario, senha, database, 0, NULL, 0))
   {   
      printf("Erro de Conexao : %s!\n", mysql_error(conexao));
   }


   // Fazendo a consulta
   if (mysql_query(conexao, sql) != 0)
   {   
      printf("Erro de SQL: %s!\n", mysql_error(conexao));

      //exit(0);
   }

   MYSQL_RES * rs = mysql_store_result(conexao); // Pega os dados retornados

   MYSQL_ROW row;

   row = mysql_fetch_row(rs); // Pega uma linha de resultado
   
   mysql_free_result(rs); // Limpa a memória utilizada
     
   mysql_close(conexao); // Desconectando
   return row[1];
}

/*
#################################################
#        FIM  Consulta Unica                    # 
#################################################
*/

/*
#################################################
#        Inicio  Query                          # 
#################################################
*/

void query(char sql[300]){   

   MYSQL * conexao;               // Cria um link para a conexão

   conexao = mysql_init(NULL);    // Inicializa o link
   // Conectando ao banco!
   if (!mysql_real_connect(conexao, host, usuario, senha, database, 0, NULL, 0))
   {   
      printf("Erro de Conexao : %s!\n", mysql_error(conexao));

   }else{
         if (mysql_query(conexao, sql) != 0)
         {   
         printf("Erro de SQL: %s!\n", mysql_error(conexao));
         }
         //printf("%d linhas afetadas!\n", mysql_affected_rows(conexao)); 
   
   }
   mysql_close(conexao); // Desconectando
   //printf("Desconectado...\n");


}
/*
#################################################
#        FIM  Query                             # 
#################################################
*/

/*
#################################################
#        Inicio  Testa conexao                  # 
#################################################
*/
void testaConexao(){   
  
   MYSQL * conexao;               // Cria um link para a conexão
   conexao = mysql_init(NULL);    // Inicializa o link
   // Conectando ao banco!
   if (!mysql_real_connect(conexao, host, usuario, senha, database, 0, NULL, 0))
   {   
      printf("Erro de Conexao : %s!\n", mysql_error(conexao));

   }else{
   
      printf("Sucesso");
   
   }
   mysql_close(conexao); // Desconectando
   printf("Desconectado...\n");
}
/*
#################################################
#        FIM  Testa conexao                     # 
#################################################
*/
