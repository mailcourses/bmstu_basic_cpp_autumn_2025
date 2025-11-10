#include <iostream>
#include <system_error>

enum class Error
{
    Success,
    Failure
};

[[nodiscard]]
Error doSomething()
{
    return Error::Failure;
}

enum class HttpCode
{
    Ok = 200,
    NotFound = 404,
    InternalServerError = 500
};

class HttpCategory : public std::error_category
{
public:
    const char* name() const noexcept override
    {
        return "http";
    }

    std::string message(int code) const override
    {
        switch(code)
        {
            case 200:
                return "ok";
            case 404:
                return "not found";
            case 500:
                return "internal server error";
            default:
                return "unknown";
        }
    }
};

std::error_code make_error_code(HttpCode code)
{
    static const HttpCategory instance;
    return std::error_code(static_cast<int>(code), instance);
}

std::error_code download(const std::string& url)
{
    if (url == "vk.com")
        return make_error_code(HttpCode::Ok);
    return make_error_code(HttpCode::InternalServerError);
}

int main()
{
    auto status = doSomething();
    if (status == Error::Failure)
    {
        std::cerr << "Failed to execute function doSomething()" << std::endl;
        //return 1;
    }
    std::cout << "Success!!!" << std::endl;

    {
        auto code = download("vk.com");
        std::cout << code << std::endl;
        std::cout << code.message() << std::endl;
    }
    {
        auto code = download("ya.ru");
        std::cout << code << std::endl;
        std::cout << code.message() << std::endl;
    }

    return 0;
}

