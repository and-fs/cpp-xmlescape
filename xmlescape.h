# ifndef _XMLESCAPE_H_
# define _XMLESCAPE_H_
// -------------------------------------------------------------------------------------------------------------------------------

/// Simple XML-escape for ASCII - character sequences.
/// 
/// :author: Andre Fritzsche-Schwalbe (https://github.com/and-fs)
/// :git: https://github.com/and-fs/cpp-xmlescape
/// :license: MIT

// -------------------------------------------------------------------------------------------------------------------------------
# include <ostream>
# include <string>
// -------------------------------------------------------------------------------------------------------------------------------
/// Streams out an XML escaped representance of ``src`` to ``out``.
/// Works only with single byte strings, but because only ordinals up to 127 are treated, encodings like utf-8 still work.
std::ostream& xml_escape(std::ostream& out, const char* src);
inline std::ostream& xml_escape(std::ostream& out, const std::string& src)
{
  return xml_escape(out, src.c_str());
}
// -------------------------------------------------------------------------------------------------------------------------------
# endif // ifdef _XMLESCAPE_H_
