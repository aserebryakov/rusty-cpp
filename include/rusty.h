// MIT License
// 
// Copyright (c) 2021 Alexander Serebryakov
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#pragma once

#include <variant>
#include <optional>

namespace rusty {
    template <typename T>
    struct Ok {
        Ok(const T& v) : value{v} {
        }

        T value;
    };

    template <typename T>
    struct Err {
        Err(const T& v) : value(v) {
        }

        T value;
    };

    template <typename OK, typename ERR>
    class Result {
        public:
            Result(Ok<OK>&& ok) : value{ok} {
            }

            Result(Err<ERR>&& err) : value{err} {
            }

            bool is_ok() const {
                return std::holds_alternative<Ok<OK>>(value);
            }

            std::optional<OK> ok() {
               if (is_ok()) {
                   return std::optional<OK>(std::get<Ok<OK>>(value).value);
               }

               return std::nullopt;
            }

            bool is_err() const {
                return std::holds_alternative<Err<ERR>>(value);
            }

            std::optional<ERR> err() {
               if (is_err()) {
                   return std::optional<ERR>(std::get<Err<ERR>>(value).value);
               }

               return std::nullopt;
            }

        private:
            std::variant<Ok<OK>, Err<ERR>> value;
    };
}
