#include <pqxx/internal/callgate.hxx>

namespace pqxx::internal::gate
{
class PQXX_PRIVATE transaction_transactionfocus : callgate<transaction_base>
{
  friend class pqxx::internal::transactionfocus;

  transaction_transactionfocus(reference x) : super(x) {}

  void register_focus(transactionfocus *focus)
  {
    home().register_focus(focus);
  }
  void unregister_focus(transactionfocus *focus) noexcept
  {
    home().unregister_focus(focus);
  }
  void register_pending_error(std::string const &error)
  {
    home().register_pending_error(error);
  }
};
} // namespace pqxx::internal::gate
