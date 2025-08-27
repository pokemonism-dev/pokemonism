# MEOWTH <sup style="font-size: .5em">PREREQUISITE PROJECT</sup>

![MEOWTH](../../../docs/assets/images/meowth.webp)


### 20250825 | 람다 파라미터 테스트

```sh
./build/debug/pokemonism/meowth/meowth-lamda-parameter
``` 

```c++
static void lambda(void (*func)(void));
static void lambda(const std::function<void ()> & func);
static void lambda(const functionObjectVoid & func);
```

함수형 파라미터를 설정할 때는 위와 같이 세 가지 케이스를 정의하자.

### 20250825 | SIZEOF(STD::FUNCTION) | OK 

```sh
./build/debug/pokemonism/meowth/meowth-sizeof-function
``` 

32 바이트여서 크다. 파라미터로 삽입하면 편한데, 크기가 크기 때문에, 잘 모르겠다.
함수형 포인터를 담아야 한다.

### TODO: 8 바이트의 VARIANT 리턴 ...