<!DOCTYPE html>
<html>
<head>
    <title>Ambil Nomor Antrian</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css">
</head>
<body class="bg-light">

<div class="container mt-5">
    <div class="card shadow-lg">
        <div class="card-header text-center bg-primary text-white">
            <h2>Ambil Nomor Antrian</h2>
        </div>
        <div class="card-body text-center">

            <button id="btnAmbil" class="btn btn-lg btn-success mb-3">
                Ambil Nomor Antrian
            </button>

            <h4 id="hasil" class="text-primary"></h4>

            <hr>

            <h5>Daftar Antrian Menunggu</h5>
            <ul id="waitingList" class="list-group"></ul>

        </div>
    </div>
</div>


<script src="https://code.jquery.com/jquery-3.7.1.min.js"></script>

<script>
    function loadWaitingList(){
        $.get("/queue/waiting", function(res){
            $("#waitingList").html("");

            res.data.forEach(item => {
                $("#waitingList").append(`
                    <li class="list-group-item">Nomor: <strong>${item.number}</strong></li>
                `);
            });
        });
    }

    $("#btnAmbil").click(function(){
        $.get("/queue/take", function(res){
            $("#hasil").html("Nomor Anda: <strong>" + res.data.number + "</strong>");
            loadWaitingList();
        });
    });

    loadWaitingList();
</script>

</body>
</html>
