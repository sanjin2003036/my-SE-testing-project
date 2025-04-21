#include <iostream>
#include <gtest/gtest.h>
using namespace std;

// Abstract Window Interface
class Window {
public:
    virtual void render() = 0;  // Render method for Window
};

// Abstract Scrollbar Interface
class Scrollbar {
public:
    virtual void render() = 0;  // Render method for Scrollbar
};
// Windows-specific Window Implementation
class WindowsWindow : public Window {
    public:
        void render() override {
            cout << "Rendering Windows Window" << endl;
        }
    };
    
    // Windows-specific Scrollbar Implementation
    class WindowsScrollbar : public Scrollbar {
    public:
        void render() override {
            cout << "Rendering Windows Scrollbar" << endl;
        }
    };
// Linux-specific Window Implementation
class LinuxWindow : public Window {
    public:
        void render() override {
            cout << "Rendering Linux Window" << endl;
        }
    };
    
    // Linux-specific Scrollbar Implementation
    class LinuxScrollbar : public Scrollbar {
    public:
        void render() override {
            cout << "Rendering Linux Scrollbar" << endl;
        }
    };
// Abstract Factory Class
class GUIFactory {
    public:
        virtual Window* createWindow() = 0;
        virtual Scrollbar* createScrollbar() = 0;
    };

    class WindowsFactory : public GUIFactory {
        public:
            Window* createWindow() override {
                return new WindowsWindow();
            }
        
            Scrollbar* createScrollbar() override {
                return new WindowsScrollbar();
            }
        };
    class LinuxFactory : public GUIFactory {
public:
    Window* createWindow() override {
        return new LinuxWindow();
    }

    Scrollbar* createScrollbar() override {
        return new LinuxScrollbar();
    }
};





TEST(WindowsTest, Render) {
    WindowsWindow window;
    WindowsScrollbar scrollbar;
    testing::internal::CaptureStdout();
    window.render();
    scrollbar.render();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Rendering Windows Window\nRendering Windows Scrollbar\n");
}

TEST(LinuxTest, Render) {
    LinuxWindow window;
    LinuxScrollbar scrollbar;
    testing::internal::CaptureStdout();
    window.render();
    scrollbar.render();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Rendering Linux Window\nRendering Linux Scrollbar\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


            
