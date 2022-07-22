cmake_minimum_required(VERSION 3.8)

project(TestSql)

add_executable(Sql "Sql.cpp")
target_link_libraries(Sql LtCore LtSql)