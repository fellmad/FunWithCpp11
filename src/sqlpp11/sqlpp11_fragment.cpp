
for (const auto& row : db(select(p.id, p.name).from(p).where(p.id > 42)))
{
    int64_t id = row.id;
    std::string name = row.name;
}