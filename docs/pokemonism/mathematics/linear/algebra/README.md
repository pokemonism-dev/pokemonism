## 1. 벡터

길이, 넓이, 부피, 질량, 온도와 같이 측정 가능한 양들은 각각의 크기를 명시함으로써 완전히 나타낼 수 있다.
반면에 속도, 힘, 가속도와 같은 양들을 나타내기 위해서는 크기와 방향이 모두 필요하다. 이러한 양들을 벡터라고 한다.
예를 들어, 바람의 속도는 시속 10 $km$ 의 남서풍과 같이 속력과 방향으로 이루어진 벡터들이다.
기하학적으로 벡터들은 종종 화살표나 유향선분으로 표현한다.

### 1.1. 벡터기하와 대수

#### 평면에서의 벡터

벡터(vector)는 한 점 $A$ 에서 다른 점 $B$까지의 이동에 대응하는 유향선분이다.
$A$에서 $B$까지의 벡터를 $\overrightarrow{AB}$ 로 나타낸다.
이때 점 $A$를 시점(initial point) 또는 꼬리(tail), 점 $B$를 종점(terminal point) 또는 머리(head)라고 한다.
보통 벡터는 단순히 $v$ 와 같이 진한 글씨체의 소문자로 나타낸다.
평면 위의 모든 점의 집합은 시점이 원점인 $O$ 인 모든 벡터들의 집합과 대응된다. 각 점 $A$ 에 대하여 원점 $O$ 를 시점으로 하는
벡터 $a=\overrightarrow{OA}$ 가 대응되고 (이러한 벡터를 때때로 위치벡터라고 한다.) 시점이 원점 $O$인 각 벡터 $a$는 그 종점이 $A$와 대응된다.
일반적으로 벡터는 좌표를 사용하여 나타낸다.
각 좌표를 그 벡터의 성분(component)이라고 한다. 벡터는 때때로 실수의 순서쌍으로 정의한다. 예를 들어 $[3, 2]\neq[2, 3]$ 이므로 순서는 중요하다.
일반적으로 두 벡터가 같다는 것은 그들의 대응하는 성분이 모두 같다는 것이다.

원점에서 시작하여 원점으로 끝나는 벡터 $[0,0]=\overrightarrow{OO}$를 실제로 그릴 수는 앖지만 이 벡터는 매우 중요하며
영 벡터(zero vector)라고 부른다. 영벡터는 $0$로 부른다.

두 벡터의 길이가 같고 방향이 같다면 두 벡터가 같다고 정의한다. 기하학적으로, 하나의 벡터를 평행 이동하여 다른 벡터에 일치시킬 수 있다면 두 벡터가 같다.
시점이 원점인 $\overrightarrow{OP}$와 같은 벡터는 표준 위치(standard position)에 있다고 한다.

__예제 1.1.__ $A=(-1, 2)$ 이고 $B=(3, 4)$일 때, $\overrightarrow{AB}$를 구하고

1. 표준 위치인 벡터로 그려라.
2. 시점이 $C=(2, -1)$인 벡터로 그려라.

```c++
#include <pokemonism/mathematics/linear/algebra/vector.hh>

using namespace pokemonism;
using namespace pokemonism::mathematics::linear::algebra;

int main(int argc, char ** argv) {
    Point<DimensionTag::Two> a(-1, 2);
    Point<DimensionTag::Two> b(3, -1); 
    
    Vector<DimensionTag::Two> first = b - a;
    
    printf("first: $\overrightarrow{AB}=(%d, %d)$\n", first[dimensional::axis::x], first[dimension::two::axis::y]);
    
    Vector<DimensionTag::Two> second = c(2, -1) + first;
    
    printf("second: $\overrightarrow{AB}=(%d, %d)$\n", second[dimensional:axis::x], second[dimension::two::axis::y]);
    
    return 0;
}
```

<!--

WINDOWS 

  -->


