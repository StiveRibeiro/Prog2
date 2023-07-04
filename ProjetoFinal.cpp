#include <iostream>                              //Alexandre Raul          RA:181139
#include <string>                                //Arthur Fernandes        RA:191107
#include <vector>                                //Celso Campaia           RA:191153
#include <locale.h>                              //Jo�o Vitor Ribeiro      RA:191318
#include <stdio.h>                               //Pedro Henrique Galeano  RA:189810
#include <fstream>
using namespace std;

struct Cliente {
    string nome;
    int codigo;
    float totaldaFatura;
};

struct Produto {
    string nome;
    int codigo;
    float valordaVenda;
    int quantidadeEstoque;
};

void cadastrarClientes(vector<Cliente>& clientes) {
    Cliente novoCliente;
    cout << "Digite o nome do cliente: ";
    getline(cin, novoCliente.nome);
    cout << "Digite o c�digo do cliente: ";
    cin >> novoCliente.codigo;
    cin.ignore();
    novoCliente.totaldaFatura = 0.0f;
    clientes.push_back(novoCliente);
    cout << "Cliente cadastrado com sucesso!\n";
}
void atualizarEstoque(vector<Produto>& produtos) {
    int codigoProduto;
    cout << "Digite o c�digo do produto: ";
    cin >> codigoProduto;
    for (Produto& produto : produtos) {
        if (produto.codigo == codigoProduto) {
            int quantidade;
            cout << "Digite a quantidade a ser adicionada ao estoque: ";
            cin >> quantidade;
            produto.quantidadeEstoque += quantidade;
            cout << "Estoque atualizado com sucesso!\n";
            return;
        }
    }
    cout << "\n\tPRODUTO N�O ENCONTRADO .\n";
}

void cadastrarProduto(vector<Produto>& produtos) {
    Produto novoProduto;
    int valordavenda;
    cout << "Digite o nome do produto: ";
    getline(cin, novoProduto.nome);
    cout << "Digite o c�digo do produto: ";
    cin >> novoProduto.codigo;
    cout << "Digite o valor de venda do produto: ";
    cin >> novoProduto.valordaVenda;
    cout << "Digite a quantidade do produto em estoque: ";
    cin >> novoProduto.quantidadeEstoque;

    produtos.push_back(novoProduto);
    cout << "Produto cadastrado com sucesso!\n";
}
void dinheiro(vector<Produto>& produtos){
    int dinheiro;
    cout<<"Metodo escolhido foi dinheiro somente pagamento a vista \n";
}
void cartaodebito(vector<Produto>& produtos){
    int cartaodebito;

}
void cartaodocliente(vector<Produto>& produtos){
    int cartaodocliente;

}

void realizandoVenda(vector<Cliente>& clientes, vector<Produto>& produtos) {

    int codigoCliente;
    cout << "Digite o c�digo do cliente: ";
    cin >> codigoCliente;
    cin.ignore();

    for (Cliente& cliente : clientes) {
        if (cliente.codigo == codigoCliente) {
            cout << "Cliente: " << cliente.nome <<"\n";

            cout<<"\n";

            cout << "Produtos dispon�veis:\n";
            for (const Produto& produto : produtos) {
            cout << "C�digo: " << produto.codigo << ", Nome: " << produto.nome << ", Valor: " << produto.valordaVenda <<"\n";
            }

            int codigoProduto;
            cout << "Digite o c�digo do produto: ";
            cin >> codigoProduto;
            int quantidade;
            cout << "Digite a quantidade: ";
            cin >> quantidade;
            for (Produto& produto : produtos) {
            if (produto.codigo == codigoProduto) {
            if (produto.quantidadeEstoque >= quantidade) {
            produto.quantidadeEstoque -= quantidade;
            cliente.totaldaFatura += produto.valordaVenda * quantidade;

            int alter;
            cout<<"M�todos de pagamento: \n";
            cout<<" 1 - dinheiro \n";
            cout<<" 2 - cart�o de d�bito \n";
            cout<<" 3 - cart�o do cliente (cr�dito) \n";
            cin>>alter;
            cin.ignore();
            switch (alter){
            case 1:
                cout<<"Metodo escolhido: dinheiro, somente pagamento a vista! \n";
                cout<<"Total a pagar "<<cliente.totaldaFatura <<" reais\n";
                break;
            case 2:
                cout<<"Metodo escolhido: cart�o de d�bito, somente pagamento a vista! \n";
                cout<<"Total a pagar "<<cliente.totaldaFatura <<" reais\n";
                break;
            case 3:
                cout<<"Metodo escolhido: cart�o do cliente, tendo como op��o pagamento a prazo! \n";
                cout<<"Total a pagar: "<<cliente.totaldaFatura <<"\n";

                break;
            }
            cout << "Venda realizada com sucesso!\n";
            } else {
            cout << "Estoque insuficiente para realiza��o da venda.\n";
            cout << "Por favor espere at� a reposi��o dos produtos.\n";
                    }
            return;
                }
            }
            cout << "\n\tPRODUTO N�O ENCONTRADO.\n";
            return;
        }
    }

    cout << "\n\tCLIENTE N�O ENCONTRADO.\n";
   }

void exibirClientes(vector<Cliente>& clientes) {
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado.\n";
        return;
    }
    cout << "Clientes cadastrados:\n";
    for (const Cliente& cliente : clientes) {
        cout << "Nome: " << cliente.nome << ", C�digo: " << cliente.codigo <<"\n";
    }
}

void buscarCliente(vector<Cliente>& clientes) {
    int codigoCliente;
    cout << "Digite o c�digo do cliente: ";
    cin >> codigoCliente;
    for (const Cliente& cliente : clientes) {
        if (cliente.codigo == codigoCliente) {
            cout << "Nome: " << cliente.nome << "\n";
            cout << "C�digo: " << cliente.codigo <<"\n";
            cout << "Total da fatura do cart�o: " << cliente.totaldaFatura <<"\n";
            return;
        }
    }
    cout << "\n\tCLIENTE N�O ENCONTRADO.\n";
}

float TotaldeVendas(vector<Cliente>& clientes) {
    float totalVendas = 0.0f;
    for (const Cliente& cliente : clientes) {
        totalVendas += cliente.totaldaFatura;
    }
    return totalVendas;
}

void calcularTotalVendasPorCliente(vector<Cliente>& clientes) {
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado.\n";
        return;
    }

    cout << "Total de vendas por cliente:\n";
    for (const Cliente& cliente : clientes) {
        cout << "Cliente: " << cliente.nome << ", Total de vendas: " << cliente.totaldaFatura <<"\n";
    }
}

void gerarRelatorio(vector<Cliente>& clientes) {
    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open()) {
        arquivo << "Relat�rio de cliente da Loja do Seu Z�ba:\n\n";
        for (const Cliente& cliente : clientes) {
            arquivo << "Cliente: " << cliente.nome << "\n";
            arquivo << "C�digo do cliente: " << cliente.codigo << "\n";
            arquivo << "Total de Vendas: " << cliente.totaldaFatura <<"reais de venda""\n";
        }

        arquivo.close();
        cout << "Relat�rio gerado com sucesso!\n";
    } else {
        cout << "Erro ao abrir o arquivo.\n";
    }
}
void gerarRelatorio(vector<Produto>& produtos) {
    ofstream arquivo("relatorio de produtos.txt");

    if (arquivo.is_open()) {
        arquivo << "Relat�rio de Produtos da Loja do Seu Z�ba: \n\n";
        for (const Produto& produto : produtos) {
            arquivo << "Produto: "<<produto.nome<<"\n";
            arquivo << "Codigo do Produto: " <<produto.codigo<<"\n";
            arquivo << "Estoque do produto: " <<produto.quantidadeEstoque<<"\n";
            arquivo << "Valor do Produto: " <<produto.valordaVenda<<"BITCOINS""\n";
        }

        arquivo.close();
        cout << "Relat�rio gerado com sucesso!\n";
    } else {
        cout << "Erro ao abrir o arquivo.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    vector<Cliente> clientes;
    vector<Produto> produtos;

    int opcao;
    do {
        cout << "\n========== Loja do Seu Z�ba =====================|    \n";
        cout<<  "============Gaste seu deinheiro==================|   \n";
        cout << "1. Cadastro de clientes                          |   \n";
        cout << "2. Cadastro de produtos                          |   \n";
        cout << "3. Realizar venda do produto                     |   \n";
        cout << "4. Atualizar produtos do estoque                 |   \n";
        cout << "5. Informa��es de status do cliente              |   \n";
        cout << "6. Relat�rio - Dos clientes cadastrados          |   \n";
        cout << "7. Fechamneto- Total de vendas do empreendimento |   \n";
        cout << "8. Fechamento - De vendas por cliente            |   \n";
        cout << "9. Gerar Relatorio de clientes txt               |   \n";
        cout << "10.Gerar Relatorio de Produtos txt               |   \n";
        cout << "11. Sair do Sistema                              |   \n";
        cout << "=================================================|   \n";
        cout<<"\n";

        cout <<  "Seja muito bem vindo ao mercado do seu Z�ba! \n";
        cout<<   "Fique � vontade! ";
        cout<<"\n";
        cout << "Selecione uma op��o para come�ar: ";
        cin >> opcao;
        cin.ignore();
        switch (opcao) {
            case 1:
                cadastrarClientes(clientes);
                break;
            case 2:
                cadastrarProduto(produtos);
                break;
            case 3:
                realizandoVenda(clientes, produtos);
                break;
            case 4:
                atualizarEstoque(produtos);
                break;
            case 5:
                buscarCliente(clientes);
                break;
            case 6:
                exibirClientes(clientes);
                break;
            case 7:
                cout << "Total de vendas do empreendimento: " << TotaldeVendas(clientes) <<"\n";
                break;
            case 8:
                calcularTotalVendasPorCliente(clientes);
                break;
            case 9:
                gerarRelatorio(clientes);
                break;
            case 10:
                gerarRelatorio(produtos);
                break;
            case 11:
                cout<<"Saindo do Sistema \n";
              break;
        }
    } while (opcao != 11);

    return 0;
}
