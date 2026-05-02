public class ArbolAvl {
    private NodoAVL raiz;

    private int altura(NodoAVL nodo) {
        if (nodo == null) {
            return 0;
        }
        return nodo.altura;
    }

    private int obtenerBalance(NodoAVL nodo) {
        if (nodo == null) {
            return 0;
        }
        return altura(nodo.izquierda) - altura(nodo.derecha);
    }

    private NodoAVL rotarDerecha(NodoAVL y) {
        NodoAVL x = y.izquierda;
        NodoAVL temp = x.derecha;

        x.derecha = y;
        y.izquierda = temp;

        y.altura = Math.max(altura(y.izquierda), altura(y.derecha)) + 1;
        x.altura = Math.max(altura(x.izquierda), altura(x.derecha)) + 1;

        return x;
    }

    private NodoAVL rotarIzquierda(NodoAVL x) {
        NodoAVL y = x.derecha;
        NodoAVL temp = y.izquierda;

        y.izquierda = x;
        x.derecha = temp;

        x.altura = Math.max(altura(x.izquierda), altura(x.derecha)) + 1;
        y.altura = Math.max(altura(y.izquierda), altura(y.derecha)) + 1;

        return y;
    }

    public void insertar(Estudiante estudiante) {
        raiz = insertarRecursivo(raiz, estudiante);
    }

    private NodoAVL insertarRecursivo(NodoAVL nodo, Estudiante estudiante) {
        if (nodo == null) {
            return new NodoAVL(estudiante);
        }

        if (estudiante.id < nodo.estudiante.id) {
            nodo.izquierda = insertarRecursivo(nodo.izquierda, estudiante);
        } else if (estudiante.id > nodo.estudiante.id) {
            nodo.derecha = insertarRecursivo(nodo.derecha, estudiante);
        } else {
            System.out.println("ID duplicado. No se insertó: " + estudiante.id);
            return nodo;
        }

        nodo.altura = 1 + Math.max(altura(nodo.izquierda), altura(nodo.derecha));

        int balance = obtenerBalance(nodo);

        // Caso LL
        if (balance > 1 && estudiante.id < nodo.izquierda.estudiante.id) {
            return rotarDerecha(nodo);
        }

        // Caso RR
        if (balance < -1 && estudiante.id > nodo.derecha.estudiante.id) {
            return rotarIzquierda(nodo);
        }

        // Caso LR
        if (balance > 1 && estudiante.id > nodo.izquierda.estudiante.id) {
            nodo.izquierda = rotarIzquierda(nodo.izquierda);
            return rotarDerecha(nodo);
        }

        // Caso RL
        if (balance < -1 && estudiante.id < nodo.derecha.estudiante.id) {
            nodo.derecha = rotarDerecha(nodo.derecha);
            return rotarIzquierda(nodo);
        }

        return nodo;
    }

    public Estudiante buscar(int id) {
        return buscarRecursivo(raiz, id);
    }

    private Estudiante buscarRecursivo(NodoAVL nodo, int id) {
        if (nodo == null) {
            return null;
        }

        if (id == nodo.estudiante.id) {
            return nodo.estudiante;
        }

        if (id < nodo.estudiante.id) {
            return buscarRecursivo(nodo.izquierda, id);
        } else {
            return buscarRecursivo(nodo.derecha, id);
        }
    }

    public void inOrden() {
        inOrdenRecursivo(raiz);
    }

    private void inOrdenRecursivo(NodoAVL nodo) {
        if (nodo != null) {
            inOrdenRecursivo(nodo.izquierda);
            System.out.println(nodo.estudiante);
            inOrdenRecursivo(nodo.derecha);
        }
    }

    public void preOrden() {
        preOrdenRecursivo(raiz);
    }

    private void preOrdenRecursivo(NodoAVL nodo) {
        if (nodo != null) {
            System.out.println(nodo.estudiante);
            preOrdenRecursivo(nodo.izquierda);
            preOrdenRecursivo(nodo.derecha);
        }
    }

    public void postOrden() {
        postOrdenRecursivo(raiz);
    }

    private void postOrdenRecursivo(NodoAVL nodo) {
        if (nodo != null) {
            postOrdenRecursivo(nodo.izquierda);
            postOrdenRecursivo(nodo.derecha);
            System.out.println(nodo.estudiante);
        }
    }

    public int obtenerAlturaRaiz() {
        return altura(raiz);
    }

    public int obtenerBalanceRaiz() {
        return obtenerBalance(raiz);
    }
}