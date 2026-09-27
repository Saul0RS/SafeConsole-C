# SafeConsole-C

Projeto universitário desenvolvido como atividade acadêmica de programação em linguagem C, com foco em segurança digital, manipulação de dados sensíveis e auditoria de ações no console.

A finalidade deste sistema é simular um ambiente prático de proteção e tratamento de informações, seguindo a proposta da atividade acadêmica: oferecer recursos para mascarar dados, validar senhas fortes, cifrar mensagens, registrar eventos de entrada e saída e permitir consulta ao histórico de ações. O programa foi pensado como uma ferramenta de apoio didático para entender conceitos de segurança da informação, manipulação de strings, lógica de validação e armazenamento de logs em C.

---

## 1. Como executar o sistema

### Opção A: executar o arquivo .exe já disponível

No diretório do projeto, você encontra o arquivo executável:

- `projetoCav1.exe`

Para usar diretamente:

1. Faça o download do arquivo `.exe` no GitHub ou baixe a pasta do projeto.
2. Abra a pasta onde ele está salvo.
3. Clique duas vezes em `projetoCav1.exe`.
4. Se o Windows pedir permissão para executar, confirme a abertura.
5. O menu principal do sistema será exibido no terminal.

> Caso o executável não abra corretamente no seu computador, siga a opção de compilação abaixo.

### Opção B: compilar o código em C e gerar o executável

Se o arquivo `.exe` não estiver funcionando, você pode compilar o código manualmente.

No terminal, dentro da pasta do projeto, execute:

```bash
gcc projetoCav1.c -o projetoCav1.exe
```

Depois rode:

```bash
./projetoCav1.exe
```

Se estiver usando o PowerShell do Windows:

```powershell
.\projetoCav1.exe
```

Também é possível gerar um executável sem extensão no Linux/macOS:

```bash
gcc projetoCav1.c -o safeconsole
./safeconsole
```

---

## 2. Menu principal do programa

Ao iniciar, o sistema apresenta o seguinte menu:

```text
-===- BEM VINDO AO SAFECONSOLE -===-
1 - Sanitizar algum dado
2 - Validador de Senha
3 - Cifra de Cesar
4 - Cifrar com XOR
5 - Logs de Auditoria
0 - Sair
R -
```

Você deve digitar o número da opção desejada e pressionar Enter.

---

## 3. Instruções de uso por funcionalidade

### 3.1 Sanitização de dados

- A opção `1` permite mascarar informações sensíveis antes de exibir ou salvar no sistema.
- O programa solicita:
  - `Digite o dado q voce quer sanitizar:`
- Exemplo:

```text
Digite o dado q voce quer sanitizar: 1234567890
```

Resultado esperado:

```text
Seu dado sanitizado: ********7890
```

#### Como funciona
- A função `mascara_dados` copia a string original.
- Mantém os últimos 4 caracteres visíveis.
- Substitui todos os caracteres anteriores por `*`.
- Isso é útil para ocultar dados como CPF, telefone, senha parcial ou identificadores sensíveis.

#### Observações
- Se a string tiver 4 ou menos caracteres, ela é exibida sem mascaramento.
- A operação é feita apenas para apresentação do valor sanitizado.

---

### 3.2 Validação de senha

- A opção `2` verifica se a senha atende a critérios de segurança.
- O programa solicita:
  - `Digite a senha:`

#### Regras da validação
A senha precisa ter:
- no mínimo 8 caracteres;
- pelo menos uma letra maiúscula;
- pelo menos uma letra minúscula;
- pelo menos um número.

#### Exemplos de retorno
- Se a senha for forte:

```text
parabens senha forte
```

- Se faltar número:

```text
Sua senha n tem numeros
```

- Se faltar letra minúscula:

```text
Sua senha n tem letra minuscula
```

- Se faltar letra maiúscula:

```text
Sua senha n tem letra maiuscula
```

- Se a senha for curta:

```text
Sua senha é curta demais !!!
```

#### Como funciona
A função `validar_senha` percorre a string e conta se existem:
- letras maiúsculas;
- letras minúsculas;
- dígitos numéricos.

Em seguida, compara esses critérios com a regra de segurança do sistema.

---

### 3.3 Cifra de César

- A opção `3` acessa a cifra de César.
- O programa pergunta:
  - `1 - criptografar`
  - `2 - descriptografar`

Em seguida solicita:
- `Digite a palavra:`
- `Digite a chave:`

#### Como usar
1. Escolha `1` para cifrar.
2. Digite a palavra que deseja proteger.
3. Informe a chave numérica.
4. O programa aplica a rotação na letra e mostra o texto cifrado.

Exemplo:

```text
Digite a palavra: casa
Digite a chave: 3
```

Resultado:

```text
A palavra cifrada e: fdvd
```

#### Descriptografar
- Escolha `2` para recuperar o texto original.
- Digite a mesma palavra cifrada e a mesma chave.

#### Observações
- A cifra considera letras maiúsculas e minúsculas separadamente.
- A lógica usa módulo 26 para manter o deslocamento dentro do alfabeto.
- O programa não criptografa números ou símbolos especiais; eles permanecem inalterados.

---

### 3.4 Cifração com XOR

- A opção `4` realiza uma cifragem usando operador XOR.
- O sistema solicita:
  - `Digite a palavra para cifrar ou decifrar:`
  - `Digite a chave usada na cifragem ou decifragem(0-255):`

#### Como usar
- Digite a palavra.
- Digite uma chave entre 0 e 255.
- O programa exibe:
  - `Hex:`
  - `Texto:`

#### Exemplo

```text
Digite a palavra para cifrar ou decifrar: segura
Digite a chave usada na cifragem ou decifragem(0-255): 12
```

Resultado:

```text
Hex: 44 58 ...
Texto: <texto cifrado>
```

#### Como funciona
- A função `cifrar_xor` percorre cada caractere da string e aplica XOR com a chave informada.
- A função `string_para_hex` converte o conteúdo para representação hexadecimal para facilitar visualização.
- A mesma lógica pode ser usada para decifrar, bastando reaplicar a mesma chave.

---

### 3.5 Logs de auditoria

- A opção `5` gerencia o histórico de ações do sistema.
- O programa pergunta:
  - `1 - consultar log`
  - `2 - listar logs`

#### Consultar log
- Escolha `1`.
- Digite o termo que deseja procurar.
- O programa verifica se esse valor está presente no histórico de registros.

Exemplo:

```text
Digite o termo para verificar: senha
```

Resultado:

```text
Log encontrado na posicao X: ...
```

Ou:

```text
Log nao encontrado!
```

#### Listar logs
- Escolha `2`.
- O sistema pergunta qual algoritmo será usado para cifrar o histórico antes de mostrar os registros.
- O usuário escolhe:
  - `1` para Cifra de César;
  - `2` para XOR.
- Em seguida, o programa solicita a chave da cifra.
- Depois disso, a função lista os logs já cifrados em tela e informa qual algoritmo foi usado.

#### Observações
- O histórico de logs tem limite de 100 entradas.
- O sistema registra ações do menu, entradas do usuário e respostas geradas pelo programa.
- A escolha da cifra e a chave usada para cifrar os logs não são armazenadas no próprio histórico, seguindo a regra proposital do projeto.
- Esse processo é realizado apenas na exibição do registro para auditoria visual, sem alterar o conteúdo original do log salvo no sistema.

---

### 3.6 Opção de sair

- A opção `0` encerra o programa.
- O sistema exibe:

```text
TCHAU
```

E finaliza imediatamente.

---

## 4. Fluxo recomendado de uso

Para testar o sistema de forma completa, siga este fluxo:

1. Abra o menu principal.
2. Use a opção `1` para testar a sanitização de um dado sensível.
3. Use a opção `2` para validar uma senha forte e uma fraca.
4. Use a opção `3` para cifrar e decifrar uma palavra com César.
5. Use a opção `4` para testar XOR com uma chave.
6. Use a opção `5` para consultar ou listar os registros criados.
7. Finalize com a opção `0`.

---

## 5. Dicas e cuidados

- Use textos curtos para facilitar a leitura no console.
- Para senhas, teste combinações com maiúsculas, minúsculas e números.
- Para XOR, mantenha a chave consistente para cifrar e decifrar a mesma mensagem.
- Se o programa não iniciar, primeiro confirme se o compilador `gcc` está instalado e se o arquivo `.c` está na mesma pasta do executável.

---

## 6. Arquivos do projeto

- `projetoCav1.c` — código principal em linguagem C.
- `projetoCav1.exe` — executável Windows do sistema.
- `README.md` — documentação do projeto.

---

## 7. Resumo

Este projeto funciona como um console de segurança e auditoria simples, com foco em: 
- mascaramento de dados sensíveis;
- validação de senhas fortes;
- criptografia de César;
- cifragem XOR;
- registro e consulta de logs de uso.

É uma solução prática para aprendizado de C, tratamento de strings e lógica de segurança básica em ambiente acadêmico.
