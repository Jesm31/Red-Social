# 🕸️ SocialGraph — Red Social con Grafos en C

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Terminal](https://img.shields.io/badge/Terminal-4EAA25?style=for-the-badge&logo=gnubash&logoColor=white)
![Estructuras de Datos](https://img.shields.io/badge/Estructuras%20de%20Datos-Grafos-orange?style=for-the-badge)

> **Simulación de una red social implementada desde cero en C, usando grafos como estructura de datos central.**  
> Agrega amigos, elimina conexiones, busca usuarios y explora relaciones — todo en consola.

</div>

---

## 🧠 ¿Por qué grafos?

Una red social **es** un grafo: los usuarios son nodos y las amistades son aristas. Este proyecto lleva esa analogía al código real. Implementado en **C puro**, sin librerías externas, demuestra cómo las estructuras de datos clásicas resuelven problemas del mundo real con elegancia y eficiencia.

---

## ⚡ Funcionalidades

| Función | Descripción |
|---|---|
| 👤 Crear usuario | Registra un nuevo perfil con nombre e ID único |
| ➕ Agregar amigo | Establece una conexión entre dos usuarios (arista bidireccional) |
| ❌ Eliminar amigo | Elimina una conexión existente entre dos usuarios |
| 🔍 Buscar usuario | Busca un nodo por nombre o ID |
| 👥 Ver amigos | Lista todas las conexiones de un usuario |
| 🗺️ Recorrido BFS/DFS | Explora la red a partir de un usuario dado |
| 🗑️ Eliminar usuario | Elimina un nodo y todas sus conexiones del grafo |
| 📋 Mostrar red completa | Visualiza todos los usuarios y sus relaciones |

---

## 🏗️ Diseño de la estructura

El grafo se implementa con **lista de adyacencia** para optimizar memoria en redes dispersas (la mayoría de redes sociales reales lo son).

```
GRAFO (Red Social)
│
├── Nodo: Ana ──── arista ──── Nodo: Carlos
│                                    │
└── Nodo: Luis ───────────────── arista
```

### Estructuras principales en C:

```c
// Nodo del grafo (usuario)
typedef struct Usuario {
    int id;
    char nombre[50];
    struct Amigo* listaAmigos;  // Lista de adyacencia
} Usuario;

// Arista (conexión/amistad)
typedef struct Amigo {
    int idAmigo;
    struct Amigo* siguiente;
} Amigo;

// El grafo completo
typedef struct RedSocial {
    Usuario* usuarios[MAX_USUARIOS];
    int totalUsuarios;
} RedSocial;
```

---


## 📚 Conceptos aplicados

- ✅ **Grafos no dirigidos** con lista de adyacencia
- ✅ **Búsqueda BFS** (Breadth-First Search)
- ✅ **Búsqueda DFS** (Depth-First Search)
- ✅ **Manejo dinámico de memoria** con `malloc` y `free`
- ✅ **Modularización** de código en C (`.h` y `.c`)

---



**sjared912@gmail.com** · [GitHub](https://github.com/Jesm31)
