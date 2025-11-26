<!DOCTYPE html>
<html>
<head>
    <title>Admin Antrian</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css">
</head>

<body class="bg-light">

<div class="container mt-5">
    <div class="card shadow-lg">
        <div class="card-header bg-warning text-dark text-center">
            <h2>Panel Admin Antrian</h2>
        </div>

        <div class="card-body">

            <div class="d-grid gap-2">
                <button id="next" class="btn btn-primary btn-lg">Panggil Antrian Berikutnya</button>
            </div>

            <h3 class="mt-4 text-center">Sedang Dilayani</h3>
            <h1 id="currentNumber" class="text-center text-success">---</h1>

            <div id="actionArea" class="text-center mt-3" style="display:none;">
                <button id="finish" class="btn btn-success">Selesaikan</button>
            </div>

            <hr>

            <h4>Daftar Menunggu</h4>
            <ul id="waitingList" class="list-group"></ul>

        </div>
    </div>
</div>


<script src="https://code.jquery.com/jquery-3.7.1.min.js"></script>

<script>
    let currentId = null;

    function loadWaiting(){
        $.get("/queue/waiting", function(res){
            $("#waitingList").html("");

            res.data.forEach(item => {
                $("#waitingList").append(`
                    <li class="list-group-item">Nomor: <strong>${item.number}</strong></li>
                `);
            });
        });
    }

    $("#next").click(function(){
        $.get("/queue/next", function(res){
            if(res.status === false){
                alert("Tidak ada antrian menunggu.");
                return;
            }

            currentId = res.data.id;
            $("#currentNumber").text(res.data.number);
            $("#actionArea").show();
            loadWaiting();
        });
    });

    $("#finish").click(function(){
        $.post(`/queue/finish/${currentId}`, {}, function(res){
            $("#currentNumber").text("---");
            $("#actionArea").hide();
            currentId = null;
            loadWaiting();
        });
    });

    loadWaiting();
</script>

</body>
</html>
