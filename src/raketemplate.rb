#!/usr/bin/env ruby
# coding: utf-8

require "rake/clean"
CLOBBER << "code.out"
CLOBBER << "actual.txt"

rule ".out" => [".c"] do |t|
  sh "gcc #{t.source} -o #{t.name}"
end

file "actual.txt" => "code.out" do
  if File.exist? "testcase.txt"
    sh "./code.out < testcase.txt > actual.txt"
  else
    sh "./code.out > actual.txt"
  end
end

task :test => ["actual.txt", "expected.txt"] do
  sh "diff actual.txt expected.txt"
end

task :default => :test
