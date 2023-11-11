#  Jogo Aleatorio

## Sistemas

* **Historia**
* **Player**
* **Monstros**
* **Itens**
* **Batalha**

## Historia

### Situação atual:

1. *```Historia: Nada```*
2. *```Sistema: Quase pronto```*

### Ideia:

*Toda a historia sera contida em um unico arquivo de texto (.txt). E dependendo da variavel 'secaoAtual' no codigo principal, ele ira pegar o respectivo bloco de texto. O trabalho de imprimir o texto, selecionar o bloco certo e salvar o proximo bloco de texto, sera feito por uma função.*

#### Modelo-no-Arquivo.txt:

```
Seção-Atual
/*
    Bloco de Historia
*/
Indicador-de-Fim => '-'
Proxima-Seção
```

### Melhorias:

*Provavelmente irá ter as possiveis escolhas que o jogador poderá fazer na secão atual. Para tornar, essa ideia mais volatil e eficiente, planejo fazer uma dessas coisas.*

1. No arquivo que irá conter a historia, no inicio, aonde haverá o nome da seção atual, colocar na frente um número que representa quantas escolhas o jogador ira ter de acordo aquela seção. Obs.: Ao meu ver esse tipo de sistema não ira ajudar em nada, so ira deixar mais complicado, provavelmente o melhor seria a segunda coisa.

2. No arquivo, historia.txt, vai seguir o modelo proposto anteriormente, porem com a adição das escolhas que iram seguir o seguinte modelo:
```
...Modelo anterior
+ 1 - Primeira escolha
+ 2 - Segunda escolha
+ 1 proxima-secao, da primeira escolha
+ 2 proxima-secao, da segunda escolha
```

Acredito que assim, será um metodo mais eficiente.

## Player

Base do sistema de Knights of Pen and Paper 2.

### Status:

* Vida (HP)
* Energia (EP)
* Dano (DM)
* Armadura (CA)
* Sorte (LK)
* Nível (LV)
* Experiencia (XP)

**Formula para os status:**

* *Vida*
    * hp -> hp_base + (constituicao * 40) + (lv * 2)
* *Energia*
    * ep -> ep_base + (intelecto * 100) + (constituicao * 10) + (sentidos * 15)
* *Dano*
    * dm -> dm_base + (constituicao * 25) + (sentidos * 35)
* *Armadura*
    * ca -> ca_base + (constituicao * 25) + (sentidos * 20)
* *Sorte*
    * lk -> lk_base + (sentidos * 35) + lv

### Atributos

* Constituição
* Sentidos
* Intelecto

#### Constituição

Atributo referente a aspectos físicos.

**Status que se beneficiam de constituição**
* Vida **40%**
* Dano **25%**
* Armadura **25%**
* Energia **10%**


#### Sentidos

Atributo referente a percepção e crítico.

**Status que se beneficiam de sentidos**
* Dano **30%**
* Sorte **35%**
* Armadura **20%**
* Energia **15%**

#### Intelecto

Atributo referente a força da mente.

**Status que se beneficiam de intelecto**
* Energia **100%**

### Classes

* Guerreiro
* Paladino
* Caçador
* Ladino
* Clerigo
* Mago

#### Guerreiro

*Foco em combate, alta resistencia, dano moderado. Eficiente para combates de longa duração.*

**Atributos**

* Constituição
    * 3
* Sentidos
    * 2
* Intelecto
    * 1

#### Paladino

*Foco em utilidade, alta resistencia (não tão alta quanto a do **guerreiro**), dano moderado, skills de utilidade. Eficiente para combates.*

**Atributos**

* Constituição
    * 3
* Sentidos
    * 1
* Intelecto
    * 2


#### Caçador

*Foco em iniciativa, dano alto, skills funcionais. Eficiente para burstar.*

**Atributos**

* Constituição
    * 2
* Sentidos
    * 3
* Intelecto
    * 1

#### Ladino

**Atributos**

* Constituição
    * 1
* Sentidos
    * 4
* Intelecto
    * 1

#### Clerigo

**Atributos**

* Constituição
    * 2
* Sentidos
    * 1
* Intelecto
    * 3

#### Mago

**Atributos**

* Constituição
    * 1
* Sentidos
    * 1
* Intelecto
    * 4

### Skills

### Inventario, equipamento etc

#### Slots

Tera um total de slots, e esses slots serão divididos em 3 tipos: **arma, armadura e acessorio**.
Terá uma estrutura, pilha, para controlar a quantidade de slots.
Exemplo:
```
Arma -> slot da arma      |           Arma
|  |                      |           |  |
|  |                      |           |{}|
|__|                      |           |[]|  -> ITEM 
 P   -> PILHA             |            P
```
Cada item ocupara um determinado espaço na pilha de slots. O jogador so podera equipar um item em seu respectivo slot.

## Monstros

## Itens

Todos os itens do jogo estarão em uma estrutura de dados, fila, que ira conter uma fila de todos os itens.

As informações de cada item, status e etc, serão mantidas em um arquivo .txt chamado **itens.txt**.

### Informação do item

Todo item contera essas caracteristicas:

```
sword {
    nome
    tipo
    valor
    especificação
}
```

O **tipo** dos itens é basicamente um metodo que serve para informar o que aquele item vai fazer, por exemplo:

Eu posso dizer que a *sword* é do tipo 1, porque este tipo ira indicar itens que do tipo *arma*.

O **tipo**, não sera o bastante para dizer aonde o **valor** ira, por isso tem a **especificação**. Por exemplo:

A *sword* é do tipo 1, que é uma arma, porem eu não em que atributo ou status, ela ira modificar. Por isso, tem a **especificação** que ira dizer aonde o **valor** ira.

* **Tipos dos itens**
    ``` c
    *   Arma       => 1
    *   Armadura   => 2
    *   Acessorio  => 3
    *   Utilizavel => 4
    ```

## Batalha

__Compilar código:__

``` c
gcc -o meu_programa main.c coisas.c
```
