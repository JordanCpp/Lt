cmake_minimum_required(VERSION 3.8)

project(TestSql)

add_executable(Sql "Sql.cpp")
target_link_libraries(Sql LtCore LtSql)

add_executable(QueryLoader "QueryLoader.cpp")
target_link_libraries(QueryLoader LtCore LtSql)

add_executable(Query "Query.cpp")
target_link_libraries(Query LtCore LtSql)