public class NodoAVL {
    Estudiante estudiante;
    NodoAVL izquierda;
    NodoAVL derecha;
    int altura;

    public NodoAVL(Estudiante estudiante) {
        this.estudiante = estudiante;
        this.izquierda = null;
        this.derecha = null;
        this.altura = 1;
    }
}