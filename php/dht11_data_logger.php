<?php
class DHT11 {
    private $link = '';

    function __construct($temperature, $humidity) {
        $this->connect();
        $this->storeInDB($temperature, $humidity);
    }

    function connect() {
        $this->link = mysqli_connect('localhost', 'root', '') or die('Cannot connect to the DB');
        mysqli_select_db($this->link, 'LandlideDetection') or die('Cannot select the DB');
    }

    function storeInDB($temperature, $humidity) {
        $query = "INSERT INTO dht11_data (humidity, temperature) VALUES ('$humidity', '$temperature')";
        $result = mysqli_query($this->link, $query) or die('Errant query: ' . $query);
    }
}

if (!empty($_GET['temperature']) && !empty($_GET['humidity'])) {
    $dht11 = new DHT11($_GET['temperature'], $_GET['humidity']);
}
?>
