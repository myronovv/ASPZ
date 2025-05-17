10) Реалізуйте програму, яка перезаписує область пам’яті між двома структурами — і цей баг не проявляється на всіх компіляторах.

![image](https://github.com/user-attachments/assets/667031b5-b644-454f-8cd7-380e4c5c02b5)

![image](https://github.com/user-attachments/assets/a348cdb5-f0ac-402b-8a94-51b8262bb868)


struct A менша за struct B.
Ми копіюємо лише sizeof(A) байтів із a в b.
Частина структури b (z) не буде ініціалізована взагалі — значення z стане сміттям
