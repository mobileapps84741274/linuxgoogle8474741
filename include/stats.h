//
// Created by guli on 31/01/18.
//

#ifndef ARIONUM_GPU_MINER_STATS_H
#define ARIONUM_GPU_MINER_STATS_H

#include <iostream>
#include <atomic>
#include <chrono>
#include <mutex>

using namespace std;

class Stats {
private:
    std::atomic<long> roundHashes;
    std::atomic<long> rounds;
    std::atomic<double> hashRate;
    std::atomic<double> avgHashRate;
    std::atomic<long> hashes;
    std::atomic<long> shares;
    std::atomic<long> blocks;
    std::atomic<long> rejections;
    std::chrono::time_point<std::chrono::high_resolution_clock> roundStart;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::mutex mutex;

    void updateHashRate();
public:

    Stats() : roundHashes(0),
              hashes(0),
              shares(0),
              blocks(0),
              rejections(0),
              rounds(-1),
              hashRate(0.0),
              avgHashRate(0.0),
              roundStart(std::chrono::high_resolution_clock::now()),
              start(std::chrono::high_resolution_clock::now()) {};

    void addHashes(long hashes);
    void newShare();
    void newBlock();
    void newRejection();

    void newRound();

    const atomic<long> &getRoundHashes() const;

    const atomic<long> &getRounds() const;

    const atomic<double> &getHashRate() const;

    const atomic<long> &getHashes() const;

    const atomic<long> &getShares() const;

    const atomic<long> &getBlocks() const;

    const atomic<long> &getRejections() const;

    const chrono::time_point<chrono::high_resolution_clock> &getRoundStart() const;

    const chrono::time_point<chrono::high_resolution_clock> &getStart() const;

    friend ostream &operator<<(ostream &os, const Stats &stats);

    const atomic<double> &getAvgHashRate() const;

};

#endif //ARIONUM_GPU_MINER_STATS_H
