#!/usr/bin/env python3
"""
Auto-updates the CSES progress section in README.md by counting .cpp files
in each category folder. Triggered by GitHub Actions on every push.
"""

import os
import re
from pathlib import Path

# ── CSES problem set categories with known totals ──────────────────────────
CATEGORIES = [
    ("1. Introductory Problems",    19),
    ("2. Sorting and Searching",    35),
    ("3. Dynamic Programming",      19),
    ("4. Graph Algorithms",         36),
    ("5. Range Queries",            19),
    ("6. Tree Algorithms",          16),
    ("7. Mathematics",              31),
    ("8. String Algorithms",        17),
    ("9. Geometry",                  7),
    ("10. Advanced Techniques",     24),
    ("11. Additional Problems",     77),
]

TOTAL_PROBLEMS = sum(t for _, t in CATEGORIES)

START_MARKER = "<!-- CSES_PROGRESS_START -->"
END_MARKER   = "<!-- CSES_PROGRESS_END -->"

def count_solutions(repo_root: Path, folder_name: str) -> int:
    folder = repo_root / folder_name
    if not folder.exists():
        return 0
    return len(list(folder.glob("*.cpp")))

def make_bar(solved: int, total: int, width: int = 20) -> str:
    filled = round(width * solved / total) if total else 0
    return "█" * filled + "░" * (width - filled)

def build_progress_block(repo_root: Path) -> str:
    rows = []
    grand_solved = 0

    rows.append("| # | Category | Solved | Progress |")
    rows.append("|---|----------|--------|----------|")

    for folder_name, total in CATEGORIES:
        solved = count_solutions(repo_root, folder_name)
        grand_solved += solved
        bar  = make_bar(solved, total)
        pct  = f"{solved}/{total}"
        emoji = "✅" if solved == total else ("🔄" if solved > 0 else "⬜")
        rows.append(f"| {emoji} | **{folder_name}** | `{pct}` | `{bar}` |")

    overall_bar = make_bar(grand_solved, TOTAL_PROBLEMS, 30)
    overall_pct = round(100 * grand_solved / TOTAL_PROBLEMS, 1)

    summary = (
        f"\n**Overall Progress &nbsp;·&nbsp; "
        f"`{grand_solved} / {TOTAL_PROBLEMS}` solved &nbsp;·&nbsp; "
        f"{overall_pct}% complete**\n\n"
        f"`{overall_bar}`\n"
    )

    return "\n".join(rows) + "\n" + summary

def update_readme(repo_root: Path) -> None:
    readme_path = repo_root / "README.md"
    content = readme_path.read_text(encoding="utf-8")

    progress_block = build_progress_block(repo_root)
    new_section = f"{START_MARKER}\n{progress_block}\n{END_MARKER}"

    pattern = re.compile(
        rf"{re.escape(START_MARKER)}.*?{re.escape(END_MARKER)}",
        re.DOTALL
    )

    if pattern.search(content):
        updated = pattern.sub(new_section, content)
    else:
        # Append before the last --- or at end of file
        updated = content + f"\n\n{new_section}\n"

    readme_path.write_text(updated, encoding="utf-8")
    print(f"✅  README.md updated — progress block refreshed.")

if __name__ == "__main__":
    repo_root = Path(__file__).resolve().parent.parent
    update_readme(repo_root)
