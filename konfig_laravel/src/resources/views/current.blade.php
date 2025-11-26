<!DOCTYPE html>
<html>
<head>
    <title>Layar Pemanggilan Antrian</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css">

    <style>
        .big-number {
            font-size: 120px;
            font-weight: bold;
        }
    </style>
</head>

<body class="bg-dark text-white">

<div class="container text-center mt-5">
    <h1>Antrian Sedang Dipanggil</h1>
    <div id="nomor" class="big-number mt-4">---</div>
</div>

<script src="https://code.jquery.com/jquery-3.7.1.min.js"></script>

<script>
    function loadCurrent(){
        $.get("/queue/current", function(res){
            if(res.data){
                $("#nomor").text(res.data.number);
            } else {
                $("#nomor").text("---");
            }
        });
    }

    setInterval(loadCurrent, 2000);
    loadCurrent();
</script>

</body>
</html>
