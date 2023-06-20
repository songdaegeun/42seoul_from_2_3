# 1. pipex

|   |   |
| :-: | - |
| Topic | Inter Process Communication, Parallel Programming |
| Related | Operating Systems |
| Stack | C |
| Evaluated | 2023-- |
| English Subject | [en.subject]() |
| Korean Subject | [ko.subject]() |

<br/>

# 2. Summary
pipex 프로젝트는 pipe(|), redirection(>, <, >>, <<)에 대해 terminal command 동작을 모방하는 것이다.

<br/>

# 3. What I learned

pipe()함수를 통한 IPC 구현 방법과 STDOUT, STDIN에 대한 duplication에 대해 학습하였다. fork 등 프로세스 관련 함수들에 대해 숙달하였다. 본 프로젝트에 대한 세부정보와 선행지식은 [Link]()에 정리하였다.

<br/>

# 4. Features

* statement1

* statement2
  
<br/>

# 5. Demo

![pipex demo](.gif)

<br/>

# 6. Flow Chart

![pipex flowchart](.png)

<br/>

# 7. How to compile the project
본 프로젝트의 결과물은 `Makefile`을 포함한다. 해당 `Makefile`은 common rules(`all`, `clean`, `fclean`, `re`)를 지원한다. 모든 소스코드들이 컴파일된 후에 프로그램이 생성된다.

> make all

<br/>

# 8. How to execute the program

다음과 같은 절차로 ~한다.

1. ~.

> ex1. ./server

2. ~.

> ex2. ./client \<server_pid> \<message to send>

3. ~.

4. ~.
