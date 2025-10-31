## Metodos Importantes
Librerias necesarias
```cpp
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <functional>
```
###  Ordenamiento
`sort()` - Ordenar elementos
```cpp
vector<int> arr = {3, 1, 4, 1, 5};
sort(arr.begin(), arr.end());                    // Ascendente: [1, 1, 3, 4, 5]
sort(arr.begin(), arr.end(), greater<int>());    // Descendente: [5, 4, 3, 1, 1]

// Ordenar por criterio personalizado
vector<pair<int, int>> pairs = {{3, 1}, {1, 4}, {2, 2}};
sort(pairs.begin(), pairs.end());               // Ordena por primer elemento, luego segundo
```

`stable_sort()` - Ordenamiento estable
```cpp
stable_sort(arr.begin(), arr.end());            // Mantiene el orden relativo de elementos iguales
```

### Busqueda
`binary_search()` - Búsqueda binaria (requiere arreglo ordenado)
```cpp
vector<int> arr = {1, 2, 3, 4, 5};
bool found = binary_search(arr.begin(), arr.end(), 3);  // true
```

`lower_bound()` y `upper_bound()`
```cpp
vector<int> arr = {1, 2, 2, 2, 5};
auto it1 = lower_bound(arr.begin(), arr.end(), 2);  // Primer 2
auto it2 = upper_bound(arr.begin(), arr.end(), 2);  // Después del último 2
int count = it2 - it1;  // Cantidad de 2s
```

`find()` - Buscar elemento
```cpp
vector<int> arr = {1, 2, 3, 4, 5};
auto it = find(arr.begin(), arr.end(), 3);
if (it != arr.end()) {
    cout << "Encontrado en posición: " << it - arr.begin() << endl;
}
```
### Operaciones con Conjuntos
`unique()` - Eliminar duplicados consecutivos
```cpp
vector<int> arr = {1, 1, 2, 2, 3, 3};
sort(arr.begin(), arr.end());
arr.erase(unique(arr.begin(), arr.end()), arr.end());  // [1, 2, 3]
```

`set_union()`, `set_intersection()`, `set_difference()`
```cpp
vector<int> a = {1, 2, 3, 4};
vector<int> b = {3, 4, 5, 6};
vector<int> result;

set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = [3, 4]

set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = [1, 2, 3, 4, 5, 6]

set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = [1, 2]
```

### Transformaciones
`reverse()` - Invertir elementos
```cpp
vector<int> arr = {1, 2, 3, 4, 5};
reverse(arr.begin(), arr.end());  // [5, 4, 3, 2, 1]
```

`rotate()` - Rotar elementos
```cpp
vector<int> arr = {1, 2, 3, 4, 5};
rotate(arr.begin(), arr.begin() + 2, arr.end());  // [3, 4, 5, 1, 2]
```

`next_permutation()` y `prev_permutation()`
```cpp
vector<int> arr = {1, 2, 3};
do {
    // Procesar permutación actual
} while (next_permutation(arr.begin(), arr.end()));
```

### Operaciones Numéricas
`accumulate()` - Suma de elementos
```cpp
vector<int> arr = {1, 2, 3, 4, 5};
int sum = accumulate(arr.begin(), arr.end(), 0);  // 15

// Con operación personalizada
int product = accumulate(arr.begin(), arr.end(), 1, multiplies<int>());
```

`partial_sum()` - Suma acumulativa
```cpp
vector<int> arr = {1, 2, 3, 4, 5};
vector<int> prefix_sum(arr.size());
partial_sum(arr.begin(), arr.end(), prefix_sum.begin());
// prefix_sum = [1, 3, 6, 10, 15]
```

`gcd()` y `lcm()` (C++17)
```cpp
int a = 12, b = 18;
int mcd = gcd(a, b);    // 6
int mcm = lcm(a, b);    // 36
```

### Extremos
`min_element()`, `max_element()`, `minmax_element()`
```cpp
vector<int> arr = {3, 1, 4, 1, 5};
auto min_it = min_element(arr.begin(), arr.end());  // Iterador al mínimo
auto max_it = max_element(arr.begin(), arr.end());  // Iterador al máximo
auto [min_it2, max_it2] = minmax_element(arr.begin(), arr.end());  // Ambos
```

`nth_element()` - Encontrar el k-ésimo elemento
```cpp
vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
nth_element(arr.begin(), arr.begin() + 3, arr.end());
// El elemento en posición 3 es el 4º menor (base 0)
```

### Predicados
`all_of()`, `any_of()`, `none_of()`
```cpp
vector<int> arr = {2, 4, 6, 8};
bool all_even = all_of(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; });  // true
bool any_odd = any_of(arr.begin(), arr.end(), [](int x) { return x % 2 == 1; });   // false
bool none_negative = none_of(arr.begin(), arr.end(), [](int x) { return x < 0; }); // true
```

`count()` y `count_if()`
```cpp
vector<int> arr = {1, 2, 2, 3, 2, 4};
int twos = count(arr.begin(), arr.end(), 2);  // 3
int evens = count_if(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; });  // 4
```

### Manipulación de Heap
`make_heap()`, `push_heap()`, `pop_heap()`
```cpp
vector<int> arr = {3, 1, 4, 1, 5};
make_heap(arr.begin(), arr.end());  // Convierte en max-heap

arr.push_back(9);
push_heap(arr.begin(), arr.end());  // Mantiene propiedad de heap

pop_heap(arr.begin(), arr.end());   // Mueve max al final
arr.pop_back();                     // Remueve el máximo
```

### Contenedores Útiles
`priority_queue` (no requiere #include <algorithm>)
```cpp
priority_queue<int> pq;              // Max-heap por defecto
priority_queue<int, vector<int>, greater<int>> min_pq;  // Min-heap

pq.push(3); pq.push(1); pq.push(4);
int max_val = pq.top();              // 4
pq.pop();
```

Verificar si un elemento existe en un set
```cpp
set<int> s = {1, 2, 3, 4, 5};
bool exists = s.find(3) != s.end();  // true
bool exists2 = s.count(3) > 0;       // true (más directo)
```

## Operaciones con Strings
Librerias adicionales para strings
```cpp
#include <string>
#include <sstream>
#include <cctype>
```

### Reverse y Sort
```cpp
string s = "hello";
reverse(s.begin(), s.end());         // "olleh"
sort(s.begin(), s.end());            // "ehllo"

// Encontrar subsecuencia
string text = "hello world";
bool found = text.find("world") != string::npos;
```

### Modificación de strings

```cpp
string s = "hello world";

// substr() - Extraer substring
string sub = s.substr(6, 5);         // "world" (desde pos 6, 5 caracteres)
string from_pos = s.substr(6);       // "world" (desde pos 6 hasta el final)

// insert() - Insertar texto
s.insert(5, " beautiful");           // "hello beautiful world"

// erase() - Eliminar caracteres
s.erase(5, 10);                      // Elimina 10 caracteres desde pos 5
s.erase(5);                          // Elimina desde pos 5 hasta el final

// replace() - Reemplazar substring
s.replace(6, 5, "universe");         // Reemplaza "world" con "universe"

// Operaciones básicas
s.push_back('!');                    // Agregar carácter al final
s.pop_back();                        // Eliminar último carácter
s += " extra";                       // Concatenar
```

### Transformaciones de Strings
```cpp
string s = "Hello World";

// Convertir a mayúsculas/minúsculas
transform(s.begin(), s.end(), s.begin(), ::toupper);  // "HELLO WORLD"
transform(s.begin(), s.end(), s.begin(), ::tolower);  // "hello world"

// Reverse
reverse(s.begin(), s.end());         // "dlrow olleH"

// Sort caracteres
sort(s.begin(), s.end());            // " HWdellloor"

// Eliminar espacios duplicados
s.erase(unique(s.begin(), s.end()), s.end());
```

### Verificación de caracteres (cctype)
```cpp
char c = 'A';
bool is_alpha = isalpha(c);          // true - es letra
bool is_digit = isdigit(c);          // false - no es dígito
bool is_upper = isupper(c);          // true - es mayúscula
bool is_lower = islower(c);          // false - no es minúscula
bool is_space = isspace(c);          // false - no es espacio
bool is_alnum = isalnum(c);          // true - es alfanumérico

// Conversión individual
char upper_c = toupper(c);           // 'A'
char lower_c = tolower(c);           // 'a'
```

### División de Strings
```cpp
// Usando stringstream
string text = "apple,banana,orange";
stringstream ss(text);
string token;
vector<string> tokens;

while (getline(ss, token, ',')) {    // Dividir por coma
    tokens.push_back(token);
}
// tokens = ["apple", "banana", "orange"]

// División por espacios
string sentence = "hello world programming";
stringstream ss2(sentence);
string word;
vector<string> words;

while (ss2 >> word) {                // Dividir por espacios automáticamente
    words.push_back(word);
}
```

### Conversion entre tipos de datos
```cpp
// String a número
string num_str = "123";
int num = stoi(num_str);             // String to int
long long_num = stoll(num_str);      // String to long long
double d = stod("123.45");           // String to double
float f = stof("123.45");            // String to float

// Número a string
int n = 123;
string str = to_string(n);           // "123"

// Con formato personalizado (usando stringstream)
stringstream ss;
ss << "Value: " << n << " percent";
string formatted = ss.str();         // "Value: 123 percent"
```

### Operaciones para Programación Competitiva
```cpp
// Verificar si es palíndromo
bool is_palindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

// Contar occurrencias de substring
int count_occurrences(string text, string pattern) {
    int count = 0;
    size_t pos = 0;
    while ((pos = text.find(pattern, pos)) != string::npos) {
        count++;
        pos += pattern.length();
    }
    return count;
}

// Eliminar caracteres específicos
string remove_chars(string s, string chars_to_remove) {
    for (char c : chars_to_remove) {
        s.erase(remove(s.begin(), s.end(), c), s.end());
    }
    return s;
}

// Verificar si es anagrama
bool are_anagrams(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

// Remover espacios del inicio y final (trim)
string trim(string s) {
    size_t start = s.find_first_not_of(" \t");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t");
    return s.substr(start, end - start + 1);
}
```

### Comparación de strings
```cpp
string s1 = "apple", s2 = "banana";

// Comparación lexicográfica
int result = s1.compare(s2);         // < 0 (s1 < s2)
bool equal = (s1 == s2);             // false
bool less = (s1 < s2);               // true (lexicográficamente)

// Comparar ignorando mayúsculas/minúsculas
bool equal_ignore_case(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a == b;
}
```

### Patrones Útiles
```cpp
// Frecuencia de caracteres
map<char, int> char_frequency(string s) {
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    return freq;
}

// Encontrar substring más larga sin repetir caracteres
int longest_unique_substring(string s) {
    unordered_set<char> seen;
    int max_len = 0, left = 0;
    
    for (int right = 0; right < s.length(); right++) {
        while (seen.count(s[right])) {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}

// Verificar si string es una rotación de otra
bool is_rotation(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    return (s1 + s1).find(s2) != string::npos;
}
```