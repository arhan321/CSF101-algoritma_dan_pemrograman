<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\QueueController;

// Route::get('/', function () {
//     return view('welcome');
// });


Route::get('/', [QueueController::class, 'index']);
Route::get('/display', [QueueController::class, 'display']);
Route::get('/admin', [QueueController::class, 'admin']);

Route::get('/queue/take', [QueueController::class, 'takeNumber']);
Route::get('/queue/next', [QueueController::class, 'callNext']);
Route::post('/queue/finish/{id}', [QueueController::class, 'finish']);
Route::get('/queue/waiting', [QueueController::class, 'waitingList']);
Route::get('/queue/current', [QueueController::class, 'current']);
Route::get('/api/queue/all', [QueueController::class, 'all']);
Route::delete('/queue/reset', [QueueController::class, 'reset']);