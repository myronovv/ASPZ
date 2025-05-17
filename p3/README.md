3.1
Запустіть Docker-контейнер і поекспериментуйте з максимальним лімітом ресурсів відкритих файлів. Для цього виконайте команди у вказаному порядку:
$ ulimit -n
$ ulimit -aS | grep "open files"
$ ulimit -aH | grep "open files"
$ ulimit -n 3000
$ ulimit -aS | grep "open files"
$ ulimit -aH | grep "open files"
$ ulimit -n 3001
$ ulimit -n 2000
$ ulimit -n
$ ulimit -aS | grep "open files"
$ ulimit -aH | grep "open files"
$ ulimit -n 3000

![image](https://github.com/user-attachments/assets/ca5f7156-5697-463c-8e61-afb59385169b)

3.2

![image](https://github.com/user-attachments/assets/38cf84f6-4699-4138-b653-db98ed14c611)

Я спробував безліч способів але perf чомусь не запускається на моєму ядрі 


3.3
Напишіть програму, що імітує кидання шестигранного кубика. Імітуйте кидки, результати записуйте у файл, для якого попередньо встановлено обмеження на його максимальний розмір (max file size). Коректно обробіть ситуацію перевищення ліміту.
![image](https://github.com/user-attachments/assets/18a39283-487f-4e19-a8f8-75d20b450e0a)

3.4
 Напишіть програму, що імітує лотерею, вибираючи 7 різних цілих чисел у діапазоні від 1 до 49 і ще 6 з 36. Встановіть обмеження на час ЦП (max CPU time) і генеруйте результати вибору чисел (7 із 49, 6 із 36). Обробіть ситуацію, коли ліміт ресурсу вичерпано.
![image](https://github.com/user-attachments/assets/7ec43a43-2ac2-49fb-bc68-d7d0381772a3)

3.5
Напишіть програму для копіювання одного іменованого файлу в інший. Імена файлів передаються у вигляді аргументів.
![image](https://github.com/user-attachments/assets/eb8049fc-cfdc-4f07-859b-d1408e866197)

3.6
Напишіть програму, що демонструє використання обмеження (max stack segment size). Підказка: рекурсивна програма активно використовує стек.
![image](https://github.com/user-attachments/assets/eb859428-b9c9-4a59-8c92-815127d177bb)

3.7
Написати сценарій, що тестує всі ulimit обмеження в одному виконанні.

#!/bin/bash

echo "testing ulimit ..."

ulimit -aH
ulimit -aS

echo "Max file size: $(ulimit -f) blocks"
echo "Max process count: $(ulimit -u)"
echo "Max open files: $(ulimit -n)"
echo "Max stack size: $(ulimit -s) kbytes"
echo "Max virtual memory: $(ulimit -v) kbytes"
echo "Max locked-in-memory size: $(ulimit -l) kbytes"
echo "Max resident set size: $(ulimit -m) kbytes"
echo "Max CPU time: $(ulimit -t) seconds"
echo "Max pending signals: $(ulimit -i)"
echo "Max nice priority: $(ulimit -e)"
echo "Max real-time priority: $(ulimit -r)"
echo "Max core file size: $(ulimit -c) blocks"

echo -e "\nEnd"





