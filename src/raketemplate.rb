#!/usr/bin/env ruby
# coding: utf-8

require "rake/clean"
CLOBBER << "code.out"
CLOBBER << FileList["actual*.txt"]

rule ".out" => [".c"] do |t|
  sh "gcc #{t.source} -o #{t.name}"
end

Dir.glob("expected*.txt").each do |expected|
  next unless expected =~ /expected(\d*)\.txt/
  num = $1
  actual = "actual#{num}.txt"
  testcase = "testcase#{num}.txt"

  file actual => "code.out" do
    if File.exist? testcase
      sh "./code.out < #{testcase} > #{actual}"
    else
      sh "./code.out > #{actual}"
    end
  end

  task :test => [actual, expected] do
    sh "diff #{actual} #{expected}"
  end
end

task :default => :test
