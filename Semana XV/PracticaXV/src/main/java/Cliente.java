public class Cliente {
    private int id;
    private String nombre;
    private double ingreso;
    private String segmento;
    private String region;
    private int score;
    private double deuda;
    private String jsonData;

    public Cliente(int id, String nombre, double ingreso, String segmento, String region, int score, double deuda, String jsonData) {
        this.id = id;
        this.nombre = nombre;
        this.ingreso = ingreso;
        this.segmento = segmento;
        this.region = region;
        this.score = score;
        this.deuda = deuda;
        this.jsonData = jsonData;
    }

    public int getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public double getIngreso() {
        return ingreso;
    }

    public String getSegmento() {
        return segmento;
    }

    public String getRegion() {
        return region;
    }

    public int getScore() {
        return score;
    }

    public double getDeuda() {
        return deuda;
    }

    public String getJsonData() {
        return jsonData;
    }
}