<?php

namespace App\Http\Controllers;

use App\Models\Queue;
use Illuminate\Http\Request;

class QueueController extends Controller
{

    //handler view
    public function index()
    {
        return view('index');
    }

    public function display()
    {
        return view('current');
    }

    public function admin()
    {
        return view('admin');
    }
    /**
     * Ambil nomor antrian baru (ENQUEUE)
     */
    public function takeNumber()
    {
        // Ambil nomor terakhir
        $lastQueue = Queue::orderBy('id', 'desc')->first();
        $newNumber = $lastQueue ? intval($lastQueue->number) + 1 : 1;

        // Simpan ke database
        $queue = Queue::create([
            'number' => str_pad($newNumber, 3, '0', STR_PAD_LEFT),
            'status' => 'waiting',
        ]);

        return response()->json([
            'status' => true,
            'message' => 'Nomor antrian berhasil dibuat',
            'data' => $queue,
        ]);
    }

    /**
     * Memanggil antrian berikutnya (DEQUEUE)
     */
    public function callNext()
    {
        // Ambil antrian menunggu paling depan
        $next = Queue::where('status', 'waiting')
            ->orderBy('id', 'asc')
            ->first();

        if (!$next) {
            return response()->json([
                'status' => false,
                'message' => 'Tidak ada antrian yang menunggu'
            ]);
        }

        // Update status menjadi dilayani
        $next->update(['status' => 'served']);

        return response()->json([
            'status' => true,
            'message' => 'Memanggil nomor antrian',
            'data' => $next
        ]);
    }

    /**
     * Menandai antrian selesai
     */
    public function finish($id)
    {
        $queue = Queue::find($id);

        if (!$queue) {
            return response()->json([
                'status' => false,
                'message' => 'Data antrian tidak ditemukan',
            ]);
        }

        $queue->update([
            'status' => 'done'
        ]);

        return response()->json([
            'status' => true,
            'message' => 'Antrian selesai',
            'data' => $queue
        ]);
    }

    /**
     * Daftar antrian menunggu
     */
    public function waitingList()
    {
        $list = Queue::where('status', 'waiting')
            ->orderBy('id', 'asc')
            ->get();

        return response()->json([
            'status' => true,
            'data' => $list
        ]);
    }

    /**
     * Antrian yang sedang dilayani
     */
    public function current()
    {
        $current = Queue::where('status', 'served')
            ->orderBy('updated_at', 'desc')
            ->first();

        return response()->json([
            'status' => true,
            'data' => $current
        ]);
    }

    /**
     * Semua data antrian
     */
    public function all()
    {
        return response()->json([
            'status' => true,
            'data' => Queue::orderBy('id', 'asc')->get()
        ]);
    }

    /**
     * Reset semua antrian
     */
    public function reset()
    {
        Queue::truncate();

        return response()->json([
            'status' => true,
            'message' => 'Semua antrian berhasil direset'
        ]);
    }
}
